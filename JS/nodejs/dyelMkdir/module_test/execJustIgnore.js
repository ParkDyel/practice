const exec = require('child_process').exec;

exec('echo \'###### for git push directory, so notting in here\' >> ' + __dirname + '/.just.ignore', function(err, stdout, stderr){
 if(err) console.error('exec error: ${error}');
});

