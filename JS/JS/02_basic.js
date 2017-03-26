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
setInterval(function () {
  var value = $('select > option:selected').val()
  $('select > option').css('color','black')
  $('select > option:selected').css('color','skyblue')

  $('textarea').val(value)
  console.log(value)
}, 1000);