function seq1() {
  return $("#section2 .statusArea .btnAtt").click();
}

function seq2() {
  return $("#section4 .preizesArea li .btnGetPreizes")[0].click();
}
$.when(seq1()).then(seq2(), function fail(){});

