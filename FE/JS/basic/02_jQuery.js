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

// // add() : 선택된 것에 다른 조건의 선택항목을 추가함.
// var selected= jQ('h1').add('h2')

// // find() : 특정 태그를 선택
// var xml = ~~~
// var xmlDoc = $.parseXML(xml)
// $(xmlDoc).find('userTag').each(function(index){
// })

// // setter
// $('img').attr('witdh', 200)
// $('img').removeAttr('width', 200)

// // css()
// var h1Color = $('h1').css('color')
// $('h1').css('backgroundColor','red')
// css setter
// $('h1').css({
//   color:function(index){
//     return color[index]
//   },
//   backgroundColor:'black'
// })

// // html(), text() : 문서 객체의 내부 접근
// var h4Html = $('h4').html()
// $('h4').html('test')
// html setter
// $(selector).html(function(index,html){
//   return index + ' : ' + html
// })

// // 객체 제거
// $(selector).first().remove()
// $(selector).remove()
// $(selector).empty()

// // 객체생성
// $('<p1></p1>').html('hello World!').attr('id','createByJQuery').appendTo('body')
// $('<img />').attr('src', 'https://lh4.ggpht.com/PGcS1hGzvW11iIMQ8Oo3H68BVkFWJHb33uXKBzmHTlyf7czF81hDVb18KazOlExARMXa=w300').appendTo('body')
// $('<img />',{
//   src : 'http://cfile238.uf.daum.net/image/2340504251C50A8E24489F',
//   id : 'blackWhiteWoman'
// }).appendTo('body')

// // 문서 객체 삽입 메소드
// $(A).appendTo(B)      // A를 B의 뒷 부분에 추가
// $(A).prependTo(B)     // A를 B의 앞 부분에 추가
// $(A).insertAfter(B)   // A를 B의 뒤에 추가
// $(A).insertBefore(B)  // A를 B의 앞에 추가
// $(A).append(B)        // B를 A의 뒷 부분에 추가
// $(A).prepend(B)       // B를 A의 앞 부분에 추가
// $(A).insert(B)        // B를 A의 뒤에 추가
// $(A).before(B)        // B를 A의 앞에 추가

// // example
// $('<body></body>').insertAfter('head')
// $('<div></div><div></div><div></div>').appendTo('body')

// var contents = [
//   {name : 'User1', id:'Dyel'},
//   {name : 'User2', id:'RuHaMa'},
//   {name : 'User3', id:'Chung'}
// ]
// $('div').append(function(index){
//   output = ''
//   output += '<h1>' + contents[index].name + '</h1>'
//   output += '<h4>' + contents[index].id + '</h4>'

//   return output
// })

// // example : 항목 큐로 돌리기
// $('html').css({
//   backgroundColor : 'black'
// })

// $('div').css({
//   color : 'skyblue',
//   backgroundColor : 'dimgray'
// })

// setInterval(function(){
//   $('div').first().appendTo('body')
// }, 2000)

// // clone() : 기존에 있는 항목의 위치를 변경하기 위해 append 계열의 함수를 사용하면 기존의 위치에서 이동되는 이를 유지하고 복사하기 위해서 다음과 같이 사용한다.
// $(selector).append($(selector2.clone())
