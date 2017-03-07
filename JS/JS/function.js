// function listen(){}선언적 함수는 다른 코드보다 먼저 해석되므로 순서와 상관없이 존재하면 된다.
// var listen = fucntion(){} 익명 함수는 다른 코드와 순서대로 해석되므로 사용되기 전에 먼저 작성되여 해석되어야 한다.


// function이 parameter를 받을 때 명시하지 않아도 함수 내부의 arguments 객체로 존재한다.
// function listen(){
//   console.log(arguments);
// }
// listen('hello', 'i', 'am', 'fine')


// closure 함수는 객체와 객체의 환경을 가지는 함수로 자바스크립트에서 내부 변수가 활용될 가능성이 있는 경우 변수를 제거하지 않는 성질을 이용하는 것.

// function closureExample(name){
//   var output = 'hello, ' + name + ' from other side.'
//   return function(){
//     console.log(output)
//   }
// }

// not Working, because closureExample just return function, so if want to run must call function, like below.
// closureExample('Dyel')

// working
// var test = closureExample('Dyel');
// test();


// setInterval과 setTimeout은 각각 id 값을 리턴하는 이를 clearTimeout, clearInterval의 매개변수로 전달한다면 동작을 중지할 수 있다.
// 타이머 함수와, 웹 요청은 웹 브라우저가 처리하는 대표적인 함수이다. 이로 인해 코드의 동작을 잘못 예측할 수 있다.

// for (var i = 0; i < 3; i++) {
//   setTimeout(function () {
//     console.log(i)
//   }, 0);
// }
// expect 0,1,2
// resurt 3,3,3

//solution
// for (var i = 0; i < 3; i++) {
//   (function (closed_i) {
//     setTimeout(function () {
//       console.log(closed_i)
//     }, 0);
//   })(i);
// }
// expect 0,1,2
// result 0,1,2
// closure와 자기 호출 함수를 활용하여 해결할 수 있다.

// 인코딩/디코딩 함수
// escape() / unescape(), encodeURI() / decodeURI(), encodeURIComponent() / decodeURIComponent
//var userUrl = 'http://dyel.net?category=축구'
// console.log(escape(userUrl)); 
// http%3A//dyel.net%3Fcategory%3D%uCD95%uAD6C -> 알파벳, 숫자, 일부 특수 문자를 제외하고 변환
// console.log(encodeURI(userUrl));
// http://dyel.net?category=%EC%B6%95%EA%B5%AC ->  escape() 함수에서 인터넷 주소에 사용되는 일부 특수 문자는 변환하지 않음 
// console.log(encodeURIComponent(userUrl)); 
// http%3A%2F%2Fdyel.net%3Fcategory%3D%EC%B6%95%EA%B5%AC -> 영어 숫자를 제외한 모든 문자 변환

// console.log(isNaN(NaN))
// console.log(isFinite(100/0))


// // object
// var output = {
//   'data' : 'hello',
//   return : function(){
//     return this.data
//   }
// }

// console.log(output['data'])
// console.log(output.data)
// console.log(output.return())

//// object에 대한 for문

// var 오브젝트 = {
//   data1 : 'Dyel'
// , data2 : 'Dior'
// , data3 : 'Dore'
// , value1 : 55
// , value2 : 77
// , value3 : 67
// , buffer : ''
// , function1 : function(key){
//   return this.key
// }
// }

// var value1='525';
// for (var key in 오브젝트){
//   console.log(key +' : ' + 오브젝트[key])
// }

// console.log('function1' in 오브젝트)

// with(오브젝트){
//   console.log(data1)
//   console.log(data2)
//   console.log(data3)
//   console.log(value1)
//   console.log(value2)
//   console.log(value3)
// }

// console.log(value1)

// console.log(오브젝트)
// delete(오브젝트.buffer)
// console.log(오브젝트)
// console.log('%d', 오브젝트.value1)

//// array with object

// function makeStudentObject(name, test1, test2, test3, test4) {
//   var willReturn = {
//     이름: name,
//     test1: test1,
//     test2: test2,
//     test3: test3,
//     test4: test4,
//     getSum: function () {
//       return this.test1 + this.test2 + this.test3 + this.test4
//     },
//     getAverage: function () {
//       return this.getSum() / 4
//     },
//     toString: function () {
//       return this.이름 + ' : \tSUM = ' + this.getSum() + '\tAVG = ' + this.getAverage()
//     }
//   }
//   return willReturn
// }

// var students = [{
//   이름: '다이엘',
//   test1: 100,
//   test2: 100,
//   test3: 100,
//   test4: 100
// }, {
//   이름: '아난나',
//   test1: 50,
//   test2: 66,
//   test3: 41,
//   test4: 2
// }, {
//   이름: '루하마',
//   test1: 40,
//   test2: 78,
//   test3: 57,
//   test4: 16
// }]

// for (var i in students) {
//   students[i].getSum = function () {
//     return this.test1 + this.test2 + this.test3 + this.test4
//   }
//   students[i].getAverage = function () {
//     return this.getSum() / 4
//   }
//   students[i].toString = function () {
//     return this.이름 + ' : \tSUM = ' + this.getSum() + '\tAVG = ' + this.getAverage()
//   }
// }

// for (var i in students) {
//   console.log(students[i].toString())
// }
// console.log('\n\n')

// students.push(makeStudentObject('잘생긴', 99, 53, 21, 45))
// students.push(makeStudentObject('머엇진', 99, 99, 99, 99))

// for (var i in students) {
//   console.log(students[i].toString())
// }

//// constructor
// var student = new Student()
// Obeject, instance : Constructor function; it's simillar class, but not equl.
// There are advantage on Constructor function, called prototype. it's share method between object made by same constructor.
function Student(id, subject1, subject2, subject3, subject4) {
  this.id = id
  this.subjects = [subject1, subject2, subject3, subject4]
}
Student.prototype = {
  getSum: function () {
    return this.subjects[0] + this.subjects[1] + this.subjects[2] + this.subjects[3]
  },
  getAverage: function () {
    return (this.subjects[0] + this.subjects[1] + this.subjects[2] + this.subjects[3]) / 4
  },
  toString: function () {
    return 'id : ' + this.subjects[0] + '\t' + this.subjects[1] + '\t' + this.subjects[2] + '\t' + this.subjects[3]
  }
}

var Dyel = new Student('Dyel', 100, 100, 100, 100)
console.log(Dyel.toString())