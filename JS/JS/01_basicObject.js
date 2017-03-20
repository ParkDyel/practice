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

// var array = new Array('h', 'e', 'l', 'l', 'o')
// console.log(array.length) // 5
// console.log(array.join('')) // hello
// console.log(array.pop() + '\t\t' + array)
// console.log(array + '\t\t' + array[array.push('.') - 1])
// console.log(array.reverse().join(''))
// console.log(array.slice(1, 3).join(''))
// console.log(array.sort().join(''))
// console.log(array.sort(function (left, right) {
//   return right-left
// }).join(''))

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

// Array.prototype.remove = function (index) {
//   this.splice(index, 1)
// }

// var array = new Array(52, 173, 103, 32, 126, 365)

// console.log(array)

// // but, this way occur dis-expect result. : [ 52, 103, 32, 365 ] 
// // because, when remove some a element, it pull array element. so some element will passed with out confirm if case.
// // index 0 : 52 > 100 --> notting to do.
// // index 1 : 173 > 100 --> remove array[1], and array[2] will be a array[1]. now array[2] is 32
// // index 2 : (expected) 103 > 100 --> remove a element, but (result) : 32 > 100 --> notting to do.
// for (var index = 0; index < array.length; index++) {
//   if (array[index] > 100) {
//     array.remove(index)
//   }
// }

// // for make expected result, this revers for case way.
// // result : [ 52, 32 ]
// for (var index = array.length; index >= 0; index--) {
//   if (array[index] > 100) {
//     array.remove(index)
//   }
// }

// console.log(array)
// array.push(25)
// console.log(array.pop())
// array.splice(0,3)
// console.log(array)

// var array = new Array(1,2,3,4,5,4,3,2,1)
// console.log('Value 3 in from head-side: ' + array.indexOf(3) + ', Value 3 in from end-side : ' + array.lastIndexOf(3))

// var array = new Array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

// var sum = 0;
// var output = '';

// array.forEach(function (element, index, array) {
//   sum += element
//   output += index + ' : ' + element + '\t ->\t SUM : ' + sum + '\n'
// }, this);
// console.log(output)

// console.log(array.map(function (element, index, array) {
//   return element * element
// }, this))

// var fillterArray = array.filter(function (element, index, array) {
//   return (element % 2) == 0
// })
// console.log(fillterArray)

// function ltFive(e, i, arr) {
//   return e < 5;
// }

// function gtFive(e, i, arr) {
//   return e >= 5;
// }

// output = ''
// console.log(array.every(ltFive) + ':' + array.every(gtFive))  // if every element of array, return true.
// console.log(array.some(ltFive) + ':' + array.some(gtFive))    // if some element of array, return true.
// reduce(), reduceRight()


//// toJSON
// var object = {
//   name : 'dyel',
//   region : 'seoul'
// }
// console.log(object.name)

// var objectJSON = JSON.stringify(object)
// objectJSON.name = 'RuHaMa'
// console.log(objectJSON.name)  // ! result : undefined

// // #### Date()

// var date = new Date()
// console.log('now : ' + date)
// // date.setDate(date.getDate() + 7)
// // console.log('after 1 week : ' + date.toLocaleString())

// Date.prototype.getInterval = function (otherDate) {
//   if (this > otherDate) {
//     return Math.floor((this.getTime() - otherDate.getTime()) / (1000 * 60 * 60 * 24))
//   } else if (otherDate > this) {
//     return Math.floor((otherDate.getTime() - this.getTime()) / (1000 * 60 * 60 * 24))
//   }
// }

// var after1Week = new Date()
// after1Week.setDate(after1Week.getDate() + 7)
// console.log('interval : ' + date.getInterval(after1Week) + '일')

// // #### Object

// var object = new Object();
// Object.defineProperty(object, 'name', {
//   get: function () {
//     console.log('GETTER')
//     return value
//   },
//   set: function (newValue){
//     console.log('SETTER')
//     value = newValue
//     return value
//   }
// })
// object.name = 'Alpa'
// console.log(object.name)

// // new Object vs Object.create() 
// // make Object from Object frame vs copy object from built Object.

// var object = Object.create({}, {
//   name: {
//     value: 'Dyel',
//     enumerable: true
//   },
//   region: {
//     value: 'Seoul',
//     enumerable: true
//   }
// })

// var person = Object.create(object, {
//   gender: {
//     value: 'Male',
//     enumerable: true
//   },
//   hobby: {
//     value: 'Football',
//     enumerable: true
//   }
// })  // create(Some object to desire inherition, {addition property})

// console.log(person.name) // result : Dyel
// // Object.preventExtensions, Object.isExtensible()
// console.log(Object.isExtensible(object))
// Object.preventExtensions(object)
// console.log(Object.isExtensible(object))
// Object.defineProperty(person,'h',{
//   value:182
// }) // !it's work?
// console.log(person.h)

// // seal(), freeze()


// // 