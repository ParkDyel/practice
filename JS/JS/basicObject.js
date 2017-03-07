// // prototype on basic type.
// var text1 = 'hello' // It's String!
// var text2 = new String('hello') // It's Object, because It had maden by Constructor!

// console.log('text1 type : ' + typeof(text1) + '\n' + 'text2 type : ' + typeof(text2))

// console.log(text1.toString())
// console.log('text1 type : ' + typeof(text1) + '\n' + 'text2 type : ' + typeof(text2))

// // text1.toExp = function(){
// //   return text1*text1
// // }
// // console.log(text1.toExp())

// text1.prototype = {
//   work : function(){
//     return 'work!'
//   }
// }

// console.log(text1.work())

// var text1 = 'hello' // It's String!
// var text2 = new String(552) // It's Object, because It had maden by Constructor!

// console.log('text1 type : ' + typeof (text1) + '\n' + 'text2 type : ' + typeof (text2))

// console.log(text1.toString())
// console.log('text1 type : ' + typeof (text1) + '\n' + 'text2 type : ' + typeof (text2))

// // It will not work. because text1 is not Obeject. when using basic method, it be obeject temporary.
// // text1.toExp = function(){
// //   return text1*text1
// // }
// // console.log(text1.toExp())

// String.prototype.work = function () {
//   return 'work!'
// }

// // String.prototype = {
// //   work: function(){
// //     return 'work'
// //   }
// // }

// console.log(text1.work())

//// Object(), Object is top-level Object of JavaScript
// var object = new Object()
// console.log(typeof(object))

// var student = {
//   name : '박동영',
//   belong : '서일대',
//   toString : function(){
//     return this.name + ' : ' + this.belong
//   }
// }

// console.log(student.toString())

// // difference between typeof() and constructor().
// var numberOfCount = []
// numberOfCount[1] = 273
// numberOfCount[2] = new Number(273)
// for (var i = 1; i < 3; i++) {
//   if (typeof(numberOfCount[i]) == 'number') {
//     console.log('numberOfCount['+i+']' + '\'s type is number')
//   } else {
//     console.log('numberOfCount['+i+']' + '\'s type is not number')
//   }
// }
// // output
// // numberOfCount[1]'s type is number
// // numberOfCount[2]'s type is not number

// for (var i = 1; i < 3; i++) {
//   if (numberOfCount[i].constructor == Number) {
//     console.log('numberOfCount['+i+']' + '\'s type is number')
//   } else {
//     console.log('numberOfCount['+i+']' + '\'s type is not number')
//   }
// }
// // output
// // numberOfCount[1]'s type is number
// // numberOfCount[2]'s type is number

//// object prototype
// Object.prototype.info = function(){
//   console.log(this)
// }

// var number = 255;
// var string = 'hello'
// console.log(number.info())
// console.log(string.info());

// // Number Object
// var number = 1214.1214
// console.log(number.toFixed(2))
// console.log((1214.1214).toFixed(2));
// console.log(Number.MAX_VALUE)
// console.log(Number.MAX_VALUE + 1)
// console.log(Number.MAX_VALUE + 0.00000000000001e+308)

// // String Object

// var string = 'hello from other side\n'
// console.log(string.length)
// console.log(string.charAt(0))
// console.log(string.charAt(6)) // 'f' of 'from'
// console.log(string.indexOf('from', 0)) // search content, begin offset.
// console.log(string.slice(6, 10)) // return 'from'
// console.log(string.split(' ', 2)) // return ['hello', 'from']

// console.log(string.slice(string.indexOf('f'), string.indexOf('m')+1).toUpperCase())

// // input method
// const readline = require('readline');

// const rl = readline.createInterface({
//   input: process.stdin,
//   output: process.stdout
// });

// rl.question('What do you think of Node.js? ', (answer) => {

//   console.log(`Thank you for your valuable feedback: ${answer}`);
//   rl.close();
// });

// Array

var array = new Array('h', 'e', 'l', 'l', 'o')
console.log(array.length) // 5
console.log(array.join('')) // hello
console.log(array.pop() + '\t\t' + array)
console.log(array + '\t\t' + array[array.push('.') - 1])
console.log(array.reverse().join(''))
console.log(array.slice(1, 3).join(''))
console.log(array.sort().join(''))
console.log(array.sort(function (left, right) {
  return right-left
}).join(''))

// review enclapsulation
// function SqrtArg(args) {
//   var argv = 1

//   args.forEach(function (element) {
//     argv *= element
//   }, this);

//   this.getValue = function () {
//     return argv
//   }
// }
// SqrtArg.prototype = {
//   print: function () {
//     return this.getValue()
//   }
// }


// var test = new SqrtArg([14, 2, 15])
// console.log(test.print())