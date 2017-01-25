var breadPad = {
  utils: {
    saveFileWithArg
  }
}

function saveFileWithArg(dist, content){
  fs.writeFile(dist, content, function(err, res){
    if(err)
      console.log(err);
    else
      console.log(res);
    });
};