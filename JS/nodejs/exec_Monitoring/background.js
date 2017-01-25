var exec = require('child_process').exec;;

var monitoring = function(object){
 this.object = 'vcgencmd ' + object;
 var child = exec(this.object, function(err, stdout, stderr){
  if(err) throw err;
  else console.log(stdout);
 })
};

var cpu_monitoring = setInterval(function(){
 monitoring('measure_temp')}
, 3000);

cpu_monitoring;
