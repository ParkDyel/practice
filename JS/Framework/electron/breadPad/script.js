console.log('I\'m working');

var { ipcRenderer } = require('electron');
// var electron = require('electron');
// var ipcRenderer = electron.ipcRendere;

var fs = require('fs')
var myCodeMirror = CodeMirror(document.getElementById('editor'));

$('.editor-button-area').on('click','#save-btn', function(e){
  e.preventDefault();
  var dist = $('#save-path').val();
  var content = myCodeMirror.getValue();
  console.log(content);
  
  if(!dist) dist = 'undefined.txt';
  breadPad.utils.saveFileWithArg(dist, content);
});

$('.editor-button-area').on('click','#remove-btn', function(e){
  e.preventDefault();
  myCodeMirror.setValue('');
});

$('.editor-button-area').on('click','#exit-btn', function(e){
  e.preventDefault();

  var chn = 'exit';
  var msg = 'hello';

  ipcRenderer.send(chn, msg);
});

