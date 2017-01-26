const path = require('path')
    , fs = require('fs')
    , promise = require('promise')
    , exec = require('child_process').exec;

function checkArgv(argv){
 /* parsing cmd argument
  process.argv.forEach(function (val, index, array) {
  console.log(index + ': ' + val);
 });
 */
 return new Promise(function(resolve, reject){
  if(argv == null){
   console.log('noting in args');
   console.log('USAGE : node dyelMkdir.js {dirPath}');
   reject(argv);
  } else {
   resolve(process.argv[2]);
  }
 })
};

function parsingPath(argv){
 /* parsing path
 'foo/bar/baz'.split(path.sep)
 Returns: ['foo', 'bar', 'baz']
*/
 return new Promise(function(resolve, reject){
  var distPath = path.normalize(argv);

  if(path.isAbsolute(distPath)){
   distPath = path.relative(__dirname, distPath);
  }
  
  resolve(distPath.split(path.sep));

 });
};

function checkDir(param){
 return new Promise(function(resolve, reject){
  var dirPath = __dirname;
  param.forEach(function(val, index, array){
   dirPath = dirPath + '/' + val;
   var exists = fs.existsSync(path);
   if(!exists){
    fs.mkdirSync(dirPath);
    exec('echo \'###### for git push directory, so notting in here\' >> '+dirPath+'/.just.ignore', function(err, stdout, stderr){
     if(err) console.error('exec error: ${error}');
    });
   }
  });
 });
};

checkArgv(process.argv[2])
 .then(parsingPath)
 .then(checkDir)
 .then(function(){
  console.log('Done');
 });
