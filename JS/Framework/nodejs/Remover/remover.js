/*
* Remover
* Dyel
* 2018.04.02
* Removing files with simple rules
*/

const os = require('os'),       // 파일 시스템을 확인하기 위해 가져왔지만, 사실 path.sep을 찾아서 더 이상 의미 없다.
  path = require('path'),       // 파일의 경로를 다루기 위해서 잘 사용하고 있다. path.sep!
  fs = require('fs'),           // 파일 시스템을 다루는 친구다. 
  promise = require('promise'); // 비동기 프로그래밍에서 동기 프로그래밍을 다루기 위해 사용할 수 있는데, 왠지 reject가 deperecated 됐다고 한다. 한번 문서를 찾아봐야겠다.

function checkArgv(argv) {
  return new Promise(function (resolve, reject) {
    // 시스템에서 인자가 정상적으로 입력되었는지 확인한다.
    // 정상적인 경우 : node remover.js {$폴더경로} {$확장자}
    if (argv.length != 4) {
      console.log('nothing in args');
      console.log('USAGE : node remover.js {dirPath} {Files Extension}');
      reject(argv);
    } else {
      param = process.argv;
      resolve(param);
    }
  })
};

function parsingPath(argv) {
  return new Promise(function (resolve, reject) {
    // 입력받은 인자 중 경로를 분석하여 절대 경로이면 이를 상대 경로로 바꿔준다.
    var distPath = path.normalize(argv[2]);
    if (path.isAbsolute(distPath)) {
      distPath = path.relative(__dirname, distPath);
      console.log("DONE : " + distPath);
    }
    // 다음 함수로 전달된 JSON 인자.
    param = {
      path: distPath.split(path.sep),
      rule: argv[3]
    };
    resolve(param);
  });
};

function checkDir(param) {
  return new Promise(function (resolve, reject) {
    // 전달받은 경로가 멀쩡한지 확인한다.
    // 근데 Mkdir에서도 그런것 같은데 함수가 뭔가 다시 한번 쪼개져야할 필요성은 있는 것 같다.
    distPath = param.path.join(path.sep);
    console.log(distPath);
    var exists = fs.existsSync(distPath);
    if (!exists) {
      console.log("Doesn\'t exists Directory. Plz Check!");
      reject(exists);
    } else {
      // 여기서 함수가 한번 분기되어야 할 것 같다.
      // mkdir 기능에서도 여기서 분기되어야 할텐데...
      let removeCount = 0;
      fs.readdirSync(distPath).forEach(function (val, index, array) {
        if (param.rule === '*') {
          fs.unlinkSync(distPath + path.sep + val);
        } else if (param.rule.toLowerCase() == val.split('.').pop().toLowerCase()) {
          fs.unlinkSync(distPath + path.sep + val);
          removeCount++;
        }
      })
      console.log(removeCount);
      resolve(removeCount);
    };
  });
};

checkArgv(process.argv)
  .then(parsingPath)
  .then(checkDir)
  .then(function (count) {
    console.log('Done : ' + count);
  });