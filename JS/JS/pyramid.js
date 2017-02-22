var strbuf;
var height
var width=0

height = 15

// for (var i = 0; i < height; i++) {
//   strbuf = ''
//   for (var k = 0; k < height - i; k++) {
//     strbuf += ' '
//   }
//   for (var k = 0; k < width; k++) {
//     strbuf += '*'
//   }
//   for (var k = 0; k < height - i; k++) {
//     strbuf += ' '
//   }
//   console.log(strbuf);
//   width++;
// }

function reverse(s){
    return s.split("").reverse().join("");
}

// for (var i = 0; i < height; i++) {
//   strbuf = ''
//   for (var k = 0; k < height - i; k++) {
//     strbuf += ' '
//   }
//   for (var k = 0; k < width-1; k++) {
//     strbuf += '*'
//   }
//   if(i!=0) strbuf = strbuf + '*' + reverse(strbuf)
//   console.log(strbuf);
//   width++;
// }

for (var i = 0; i < height; i++) {
  strbuf = ''
  for (var k = 0; k < height - i; k++) {
    strbuf += ' '
  }
  for (var k = 0; k < i-1; k++) {
    strbuf += '*'
  }
  if(i!=0) strbuf = strbuf + '*' + reverse(strbuf)
  console.log(strbuf);
  width++;
}
