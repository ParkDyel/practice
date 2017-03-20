// window
window.open(URL,name,features,replace) // create new window.
// example
window.open('http://www.naver.com')
window.open('http://www.naver.com', 'child', 'width=600, height=300', true)

// When close child panel, child will be destroyed.
var child = window.open('','','width=300, height=200')
if(child){
child.document.write('<h4>Hello from Parent Windows</h4>')
child.document.write('<p>nano</p>')
} else {
  alert('Plz check out Pop-up settting.') 
}

// Obj screen is about browser screen.
// Obj location is about address line.
location.reload() // equl F5
location.assign(URL) // move to URL
location.replace(URL) // replace this windows to URL
// Err; URL: www.naver.com 
// Work; URL: http://www.naver.com

// Obj navigator is about Browser Environment.
navigator.platform // OS ? Win32. exatly it's mean Browser's OS Version. even if OS is 64 bit, it's have 32 bit cause browser installer was 32bit.
navigator.appName // Browser Name
navigator.language // used language.