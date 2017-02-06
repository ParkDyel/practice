var targets = [{
    tag: "#section4 .preizesArea li .btnGetPreizes",
    index: 1
  },
  {
    tag: "#section2 .statusArea .btnAtt",
    index: -1
  }
];

for (var i = 0; i < targets.length; i++) {
  (function (i) {
    this.click = function () {
      if (this.index !== -1)
        $(this.tag)[this.index].click();
      else
        $(this.tag).click();
    }
    this.click();
  }).call(targets[i]);
}