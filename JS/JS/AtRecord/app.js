const fs = require('fs'),
  promise = require('promise'),
  readline = require('readline')

var stdinOut = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

function checkArgv(argv) {
  return new Promise(function (resolve, reject) {
    if (argv == null) {
      resolve('toggle')
    } else if (argv == '-s') {
      resolve('check')
    } else {
      console.log('ERR_0:USAGE:\n 1. for toggle state : node AtRecord\n 2.Check loged state : node AtRecord -s\n')
      reject(argv)
    }
  })
};

function checkState(param) {
  return new Promise(function (resolve, reject) {
    switch (param) {
      case 'toggle':
      case 'check':
        var path = 'data.json'
        if (fs.existsSync(path)) {
          if (fs.accessSync(path)) {
            var temp = fs.readFileSync(path, 'utf8')
            temp = JSON.stringify(temp)
            var state = temp.slice(-1)[0]
            var params = {
              flag: param,
              json: temp,
              state: state
            }
            resolve(params)
          } else {
            // file is exist, but cannot access it.
            console.log('ERR 2:Cannot Access Data.json')
            reject(param)
          }
        } else {
          // file is not exist.
          console.log('is it first use this code? there is nothing')
          var params = {
            flag: param,
            json: JSON.stringify(),
            state: ''
          }
          resolve(params)
        }

        break;
      default:
        console.log('ERR_1:Unexpected Parameter passed')
        reject(param)
        break;
    }
  })
};

function toggleState(params) {
  return new Promise(function (resolve, reject) {
    if (params.flag == 'toggle') {
      var toDay = new Date().toLocaleDateString()
      if (params.state.date == toDay) {
        // check YesterDay State
        // var YesterDay = params.json.slice(-1)[0]
        // if (YesterDay.state == 'ONLINE') {
        //   console.log('didn\'t check out Yester Day?')
        //   stdinOut.on('line', function (cmd) {
        //     console.log('You just typed: ' + cmd)
        //   });
        // } else if (YesterDay.state == 'OFFLINE') {
        // }
        var nowDate = new Date()
        params.state.out = nowDate.getTime('en-US', {
          hour12: false,
          hour: "numeric",
          minute: "numeric"
        })
        params.state.state = 'OFFLINE'
        var dataTemp = JSON.parse(params.json)
        dataTemp.push(params.state)
        params.json = JSON.stringify(dataTemp)
        resolve(fs.writeFileSync('data.json', json, 'utf8'))

      } else {
        // not attendance today
        var newDate = {}
        var nowDate = new Date()
        newDate.date = nowDate.toLocaleDateString()
        newDate.in = nowDate.getTime('en-US', {
          hour12: false,
          hour: "numeric",
          minute: "numeric"
        })
        newDate.state = 'ONLINE'
        var dataTemp = JSON.parse(params.json)
        dataTemp.push(params.state)
        dataTemp.push(params.newDate)
        params.json = JSON.stringify(dataTemp)
        resolve(fs.writeFileSync('data.json', json, 'utf8'))
      }
    } else if (params.flag == 'check') {
      console.log(params.state)
      return 0;
    } else {
      console.log('ERR_3:Unexpected Parameter Passed.')
      reject(param[0])
    }
  })
};

checkArgv(process.argv[2])
  .then(checkState)
  .then(toggleState)
  .then(function (result) {
    console.log('result : ' + result)
  });