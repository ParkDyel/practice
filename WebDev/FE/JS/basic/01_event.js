// Code_01
// Basic Event Adder
var headerP = document.createElement('p')
var textNode = document.createTextNode('It\'s me!')
headerP.id = 'header'
headerP.style.fontSize = 24 + 'px'
headerP.appendChild(textNode)
document.body.appendChild(headerP)

var haders = document.getElementById('header')
header.onclick = function (e) {

  var event = e || window.event // window.event for ES6
  console.log('header was clicked')
  console.log(this.style.fontSize + ':' + this.style.color)
  this.style.fontSize = 28 + 'px'
  this.style.color = 'red'
}

// Code_02
// Counter
var countP = document.createElement('p')
var count2P = document.createElement('p')
var tN = document.createTextNode('0')
var tN2 = document.createTextNode('0')
countP.id = 'counterClick'
count2P.id = 'counter2Click'
countP.style.fontSize = 24 + 'px'
countP.style.backgroundColor = 'red'
count2P.style.fontSize = 24 + 'px'
count2P.style.backgroundColor = 'red'
countP.appendChild(tN)
count2P.appendChild(tN2)
document.body.appendChild(countP)
document.body.appendChild(count2P)

var N = document.getElementById('counterClick')
var N2 = document.getElementById('counter2Click')

N.onclick = function (e) {
  this.innerHTML = Number(this.innerHTML) + 1
  N2.onclick()
}

N2.onclick = function (e) {
  this.innerHTML = Number(this.innerHTML) + 1
}

// Code_03
// editting default event listener.
/*
<!DOCTYPE html>
<html lang="en">

<head>
  <title></title>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="css/style.css" rel="stylesheet">
</head>

<body>
  <form id='signIn'>
    <label for="name">이름</label>
    <input type="text" name="name" id="name" /><br />
    <label for="passwd">PASSWD</label>
    <input type="password" name="passwd" id="passwd" /><br />
    <label for="passwdChecker">PASSWD</label>
    <input type="password" id="passwdChecker" /><br />
    <input type="submit" value="제출" />
  </form>
</body>
<footer>
  <script>
    window.onload = function () {
      document.getElementById('signIn').onsubmit = function () {
        var passwd = document.getElementById('passwd').value
        var passwdChecker = document.getElementById('passwdChecker').value
        if (passwd == passwdChecker) {
          alert('Done')
        } else {
          alert('not equl PASSWD and PASSWDCHECKER')
        }
      }
    }
  </script>
</footer>

</html>

<!DOCTYPE html>
<html lang="en">

<head>
  <title></title>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>

  <form id='signIn' onsubmit="return signInSubmit(this)">
    <label for="name">이름</label>
    <input type="text" name="name" id="name" /><br />
    <label for="passwd">PASSWD</label>
    <input type="password" name="passwd" id="passwd" /><br />
    <label for="passwdChecker">PASSWD</label>
    <input type="password" id="passwdChecker" /><br />
    <input type="submit" value="제출" />
  </form>
</body>
<footer>
  <script>
    function signInSubmit(e) {
      var passwd = document.getElementById('passwd').value
      var passwdChecker = document.getElementById('passwdChecker').value
      if (passwd == passwdChecker) {
        alert('Done')
      } else {
        alert('not equl PASSWD and PASSWDCHECKER')
      }
    }
  </script>
</footer>

</html>
*/

// Code_04
// Event Bubbling Handling
var countP = document.createElement('p')
var count2P = document.createElement('p')
var tN = document.createTextNode('AREA')
var tN2 = document.createTextNode('AREA')
countP.id = 'counterClick'
count2P.id = 'counter2Click'
countP.setAttribute('num', '0')
count2P.setAttribute('num', '0')
countP.style.fontSize = 24 + 'px'
countP.style.backgroundColor = 'red'
count2P.style.fontSize = 24 + 'px'
count2P.style.backgroundColor = 'red'
countP.appendChild(tN)
count2P.appendChild(tN2)
document.body.appendChild(countP)
countP.appendChild(count2P)


var N = document.getElementById('counterClick')
var N2 = document.getElementById('counter2Click')

N.onclick = function (e) {
  this.setAttribute('num', Number(this.getAttribute('num')) + 1) 
}

N2.onclick = function (e) {
  // It's load not only N2.onclick but also N.onclick. because N2 is child of N.
  this.setAttribute('num', Number(this.getAttribute('num')) + 1) 
  // to prevent bubbling.
  if(event.stopPropagation){
    event.stopPropagation()
  } else {
    event.cancelBuble = ture
  }
}

// Code_05
// add Event listener DOM 2 Level
// addEventListener(eventName, hanlder, useCapture=false)