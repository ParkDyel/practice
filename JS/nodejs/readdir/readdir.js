const os = require('os'),
  path = require('path'),
  fs = require('fs'),
  promise = require('promise');

var temp = '';

function checkArgv(argv) {
  /* parsing cmd argument
   process.argv.forEach(function (val, index, array) {
   console.log(index + ': ' + val);
  });
  */
  return new Promise(function (resolve, reject) {
    if (argv == null) {
      console.log('noting in args');
      console.log('USAGE : node dyelMkdir.js {dirPath}');
      reject(argv);
    } else {
      resolve(process.argv[2]);
    }
  })
};

function parsingPath(argv) {
  /* parsing path
 'foo/bar/baz'.split(path.sep)
 Returns: ['foo', 'bar', 'baz']
*/
  return new Promise(function (resolve, reject) {
    var distPath = path.normalize(argv);

    if (!path.isAbsolute(distPath)) {
      distPath = path.resolve(__dirname, distPath);
    }
    temp = distPath;
    resolve(distPath);
  });
};

function checkDir(param) {
  return new Promise(function (resolve, reject) {
    var dirPath = param;
    var exists = fs.existsSync(dirPath);
    if (!exists) {
      console.log("does not exist the folder.")
      reject(param);
    } else {
      resolve(fs.readdirSync(dirPath));
    }
  });
};

function make2dNumber(arr) {
  return new Promise(function (resolve, reject) {
    arr.forEach(function (value, array, index) {
      var extName = path.extname(value);
      var fileName = path.basename(value, extName);
      if (fileName.length === 1) {
        newFileName = '0' + fileName;
        fs.renameSync(path.join(temp + path.sep + fileName + extName), path.join(temp + path.sep + newFileName + extName))
        arr[index] = path.join(temp + path.sep + newFileName + extName);
      }
    })
    resolve(temp);
  })
}

function splitArray(arr) {
  return new Promise(function (resolve, reject) {
    arr.reverse();
    arr.forEach(function (value, array, index) {
      var extName = path.extname(value);
      var fileName = path.basename(value, extName);
      var newFileName = Number(fileName) + 28;
      fs.renameSync(path.join(temp + path.sep + fileName + extName), path.join(temp + path.sep + newFileName + extName))
    })
    resolve(arr);
  })
}

checkArgv(process.argv[2])    // just check argv insert or not
  .then(parsingPath)          // chage to path argv to absolute path
  .then(checkDir)             // check dir exist or not, if exist, return readdirSync
  .then(make2dNumber)         // make 0, 1, 2 to 00, 01, 02 becaust want to [00, 01, 02] but original array is [0, 1, 11, 12, 13]
  .then(checkDir)             // so i added this funtion to reload list
  .then(splitArray)           // reverse array becaust if not reverse 0.png overload 28.png even if it was existed. and rename + 28(which array.length)
  .then(function (addPath) {
    console.log(addPath);     // but promise err console showing something wrong 'PS C:\Users\Administrator\practice\JS\nodejs\readdir> node .\readdir.js C:\Users\Administrator\Desktop\outImgs (node:7400) UnhandledPromiseRejectionWarning: Unhandled promise rejection (rejection id: 2): Error: ENOENT: no such file or directory, rename 'C:\Users\Administrator\Desktop\outImgs\9.png' -> 'C:\Users\Administrator\Desktop\outImgs\37.png'' maybe it's from Async.
    // it's just from line 62, it was 'value = ~', and i fix to 'arr[index] = ~'
    // NO!!!! it's show aging. it was not working 'arr[index] = ~'
    // i think resolve working before forEach working complite...
  });
