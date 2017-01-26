const promise = require('promise');

function async1 (param) {
    return new Promise(function(resolve, reject) {
	console.log('async1\'s param : ' + param);
        resolve(param*2);
    });
}
function async2 (param) {
    return new Promise(function(resolve, reject) {
        if(param == 2){
		reject(param);
	}
 	else {
		console.log('async2\'s param : ' + param);
		resolve(param*3);
	}
    });
}
function async3 (param) {
    return new Promise(function(resolve, reject) {
	console.log('async3\'s param : ' + param);
        resolve(param*4);
    });
}
 
var start = 1;
async1(start)
    .then(async2)
    .then(async3)
    .then(result => {
        console.log(result); // 24
    });
