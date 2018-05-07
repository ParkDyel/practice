/*
  Input   : "Hello from the other side."
  output  : "side. other the from Hello"
*/
const readline = require('readline'),
  promise = require('promise')

// rl.on('SIGINT', () => {
//   rl.question('Are you sure you want to exit? ', (answer) => {
//     if (answer.match(/^y(es)?$/i)) rl.pause();
//   });
// });

let getStdin = (args) => {
  return new Promise(resolve => {
    if (args != 3) {
      let pipe = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });
      pipe.question('Plz Input String :', (answer) => {
        pipe.close()
        resolve(answer)
      })
    } else if (args == 3) {
      resolve(argv[3])
    } else {
      reject("Argv Error")
    }
  })
}

let reverseString = (str) => {
  return new Promise(resolve => {
    resolve(str.split("").reverse().join(""))
  })
}
let translocateString = (str) => {
  return new Promise(resolve => {
    resolve(str.split(" ").reverse().join(" "))
  })
}

let replaceDot = (str) => {
  return new Promise(resolve => {
  let res;
  str = str.split(" ")
  str.forEach((element, idx, arr) => {
    targetIdx = element.search(new RegExp(/\W/))
    if (targetIdx != -1) {
      temp = arr[idx][targetIdx]
      arr[idx] = element.replace(new RegExp(/\W/), "")
      arr[idx] = arr[idx] + temp
    }
    return element
  });
  // console.log(`TEST after str.forEach : ${str}`)
  resolve(str.join(" "))
  })
}

let main = (argv) => {
  {
    //Check Argv
    console.log(`Args : ${argv.length}`);
    argv.forEach((e, idx, array) => {
      console.log(`${argv[idx]} : ${e}`);
    });
  }

  output = getStdin(argv.length)
    .then(reverseString)
    .then(translocateString)
    .then(replaceDot)
    .then( ret => {
      console.log(`OUTPUT : ${ret}`)
    })
}

//Check this process have parent
if (typeof module != 'undefined' && !module.parent) {
  main(process.argv);
}