function auto(arr, callback) {
  $("#section2 .statusArea .btnAtt").trigger("click");
  callback();
}

auto(1, function () {
  $("#section4 .preizesArea li .btnGetPreizes")[0].click()
})