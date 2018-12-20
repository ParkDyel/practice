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
img.align = "middle" // It's not work on me.
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

// Code_05
// style
// in JavaScript "backgroundColor = 'red'" is equl "backgorund-color:red" in CSS Style.

// Code_06
// removeNode 
// removeChild(Node)

var header = document.getElementsByTagName('header')
document.body.removeChild(header)

// Code_07
// Application : Clock
var clockP = document.createElement('p')
var textNode = document.createTextNode('Time')
clockP.appendChild(textNode)
clockP.id = 'clock'
document.body.appendChild(clockP)

var clock = document.getElementById('clock')

function ticTok() {
  setInterval(function () {
    clock.innerHTML = new Date().toLocaleString()
  }, 1000)
}

ticTok()

// Code_08
// Application : Animation with Position

var sunP = document.createElement('p')
var earthP = document.createElement('p')
var moonP = document.createElement('p')
var tN0 = document.createTextNode('@')
var tN1 = document.createTextNode('O')
var tN2 = document.createTextNode('0')
sunP.id = 'sunP'
earthP.id = 'earthP'
moonP.id = 'moonP'
sunP.appendChild(tN0)
earthP.appendChild(tN1)
moonP.appendChild(tN2)
document.body.appendChild(sunP)
document.body.appendChild(earthP)
document.body.appendChild(moonP)

var sun = document.getElementById('sunP')
var earth = document.getElementById('earthP')
var moon = document.getElementById('moonP')

sun.style.position = 'absolute'
earth.style.position = 'absolute'
moon.style.position = 'absolute'
// about Sun Position, he never move on.
sun.style.left = 250 + 'px'
sun.style.top = 200 + 'px'

var earthAngle = 0;
var moonAngle = 0;

function start() {
  setInterval(function () {
    var earthLeft = 250 + 150 * Math.cos(earthAngle)
    var earthTop = 200 + 150 * Math.sin(earthAngle)
    var moonLeft = earthLeft + 50 * Math.cos(moonAngle)
    var moonTop = earthTop + 50 * Math.sin(moonAngle)

    earth.style.left = earthLeft + 'px'
    earth.style.top = earthTop + 'px'
    moon.style.left = moonLeft + 'px'
    moon.style.top = moonTop + 'px'

    earthAngle += 0.1;
    moonAngle += 0.3;
  }, 1000 / 30)
}

// Code_09
// Application : Data Flow of WWW

function returnRandomInt(limit) {
  return Math.round(Math.random() * limit)
}

function returnRandomAlphabet() {
  var alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
  return alphabet.charAt(returnRandomInt(25))
}

function returnRandomSpeed(max) {
  return Math.random() * max - Math.random() * max
}

// Constructor
var canvasWidth = screen.width
var canvasHeight = screen.height

function MovingText() {
  this.x = returnRandomInt(canvasWidth)
  this.y = returnRandomInt(canvasHeight)
  this.vx = returnRandomSpeed(10)
  this.vy = returnRandomSpeed(10)

  this.body = document.createElement('p')
  this.body.innerHTML = returnRandomAlphabet();
  this.body.style.position = 'absolute'

  document.body.appendChild(this.body)
}

MovingText.prototype.move = function () {
  if (this.x < 0 || this.x > canvasWidth) {
    this.vx *= -1
  }
  if (this.y < 0 || this.y > canvasHeight) {
    this.vy *= -1
  }

  this.x+=this.vx
  this.y+=this.vy
  this.body.style.left = this.x +'px'
  this.body.style.top = this.y +'px'
}

function start(){
  var movingTexts =[]

  for(var i=0;i<100;i++){
    movingTexts.push(new MovingText())
  }

  setInterval(function(){
    for(var i in movingTexts){
      movingTexts[i].move();
    }
  }, 1000/60)
}]]