const path = require('path'),
  fs = require('fs');

function parsingPath(argv) {
  /* parsing path
 'foo/bar/baz'.split(path.sep)
 Returns: ['foo', 'bar', 'baz']
*/
  return new Promise(function (resolve, reject) {
    var distPath = path.normalize(argv);

    if (path.isAbsolute(distPath)) {
      distPath = path.relative(__dirname, distPath);
    }

    resolve(distPath.split(path.sep));

  });
};

function checkDir(param) {
  return new Promise(function (resolve, reject) {
    var dirPath = __dirname;
    param.forEach(function (val, index, array) {
      dirPath = dirPath + path.sep + val;
      console.log(dirPath);
      console.log(fs.existsSync(dirPath));
    });
  });
};

parsingPath(process.argv[2])
  .then(checkDir);