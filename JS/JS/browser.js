// window
window.open(URL,name,features,replace) // create new window.
// example
window.open('http://www.naver.com')
window.open('http://www.naver.com', 'child', 'width=600, height=300', true)

// When close child panel, child will be destroyed.
var child = window.open('','','width=300, height=200')
child.document.write('<h4>Hello from Parent Windows</h4>')
child.document.write('<p>nano</p>') 