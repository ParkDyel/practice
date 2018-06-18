function fnMove(seq) {
  var offset = $("#section" + seq).offset();
  $('html, body').animate({
    scrollTop: offset.top
  }, 400);
};