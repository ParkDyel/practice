const destPath = './static/images';
const fs = require('fs');

list = fs.readdirSync(destPath)
list.forEach(function(element) {
  console.log("<img src=\"./static/images/" + element + "\" />")
}, this);