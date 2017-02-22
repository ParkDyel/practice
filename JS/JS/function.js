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