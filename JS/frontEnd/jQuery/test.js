var count=0;

function autoClick(tag) {
  $(tag).click();
}
function autoClick2(tag, index) {
  $(tag)[index].click();
}

$(document).keydown(function(event) {
  if (event.keyCode == '13') {
    if(count===0)
    {
      autoClick("#section2 .statusArea .btnAtt");
    } else {
      autoClick2("#section4 .preizesArea li .btnGetPreizes", 1);
    }
    count++;
}});