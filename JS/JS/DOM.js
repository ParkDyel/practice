// Code_01
// create <h1></h1> in body, and append textNode.
// result : ... <h1>Hello from other side</h1></body>

var header = document.createElement('h1')
var textNode = document.createTextNode('Hello from other side')

header.appendChild(textNode)
document.body.appendChild(header)

// Code_02
// append img on WWW

var img = document.createElement('img')
img.src = "http://esq.h-cdn.co/assets/15/41/768x950/gallery-1444418914-emilia-clarke-sexiest-woman-alive-2015-005.jpg"
img.align = "middle"  // It's not work on me.
img.data = "hell0" // It will not work.
img.setAttribute('data', "hello") // It is right access.
document.body.appendChild(img)


// code_03
// innerHTML function.
// document.body.innerHTML = 'DataString'
// <h1>innerHTML:{DataString}</h1>


var test = document.createElement('p')
textNode = document.createTextNode('Hello from other Side.')
test.id = 'test'
test.appendChild(textNode)
document.body.appendChild(test)
var idTest = document.getElementById('test')
idTest.innerHTML = "Sasasasasasaaaaaa..."

// Code_04
// getElementByTagName(TagName)

var header = document.createElement('h1')
var header2 = document.createElement('h1')
var textNode = document.createTextNode('Hello from other side')
var textNode2 = document.createTextNode('Hello from other side')

header.appendChild(textNode)
header2.appendChild(textNode2)
document.body.appendChild(header)
document.body.appendChild(header2)

var headers = document.getElementsByTagName('h1')
for (var index = 0; index < headers.length; index++) {
  headers[index].setAttribute('style', "font-size:14px")
}
/*
Suppose you have this HTML :
<input name="test" class="cssclassname">

You'd got it with
1. document.getElementsByTagName('input')
2. document.getElementsByName('test')
3. document.getElementsByClassName('cssclassname')
*/

