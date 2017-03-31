// // equal window.onload(), third is shortCut
// $(document).ready(function () {
//   console.log('first print')
// })
// $(document).ready(function () {
//   console.log('second print')
// })
// $(function () {
//   console.log('third print')
// })

// // wildcard selector 
// $('*').css('color', 'cyan');


// // selector
// $('h4, p').css('color','skyblue')

// // id selector
// $('#title').css('color', 'indianred')

// // class selector
// $('.inBody').css('color', 'rebeccapurple')

// // child selector
// $('body > li').css('color', 'yellowgreen')

// // Descendant selector
// $('body li').css('color', 'skyblue')

// // Attribute selector
// $('input[type="text"]').val("hello jQuery!")

// // fillter selector
// setInterval(function () {
//   var value = $('select > option:selected').val()
//   $('select > option').css('color','black')
//   $('select > option:selected').css('color','skyblue')

//   $('textarea').val(value)
//   console.log(value)
// }, 1000);

// // array : each
// $(document).ready(function () {
//   var array = [{
//       name: 'dyel',
//       link: 'https://kdr1009.blog.me'
//     },
//     {
//       name: 'naver',
//       link: 'https://www.naver.com'
//     },
//     {
//       name: 'google',
//       link: 'https://www.google.com'
//     }
//   ]

//   $.each(array, function (index, item) {
//     var temp = '';
//     temp += '<p>' + item.name + ' : ' + item.link + '</p>'

//     document.body.innerHTML += temp
//   })
// })
// array.forEach(function(item,index){})

// // add/remove Class 
// $(document).ready(function () {
//   $('h4').each(function (index, item) {
//     item.addClass('high-light')
//     //this.addClass('high-light')  
//   })
// })

// // extend
// $(document).ready(function () {
//   var object = {
//     time: 'what are u doing now?'
//   }
//   $.extend(object, {
//     opinion: 'study',
//     true: 'nothing'
//   })
//   console.log(object)
// });

// // noConflict : $를 사용하는 다음 프레임워크와의 충돌을 방지한다.
// $.noConflict()  // jQuery의 식별자 $를 사용할 수 없다.

// var jQ = jQuery
// jQ(documnet).ready(function(){
//   jQ('h1')
// })

// // fillter
// jQ('h1').css('background', 'orage')
//   .filter(':even').css('color', 'white')
//   .end()
//   .filter('odd').css('color', 'red')

// // eq(); first(), last() : 목록에서 순서에 따라 특정 요소를 선택
// jQ('h1').eq(0).css('background', 'skyblue') // first()
// jQ('h1').eq(-1).css('background', 'red')    // last()

// // adD() : 선택자에 항목을 추가함.
// var selected= jQ('h1').add('h2')

// // find() : 특정 태그를 선택
// var xml = ~~~
// var xmlDoc = $.parseXML(xml)
// $(xmlDoc).find('userTag').each(function(index){
// })
