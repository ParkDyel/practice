var vueCounter = new Vue({
  el: '#vueCounter', 
  data: {
    number: 0
  },
  // app 뷰 인스턴스를 위한 메소드들
  methods: {
    increment: function() {
      // 인스턴스 내부의 데이터모델에 접근 할 땐,
      // this 를 사용한다.
      this.number++;
    },
    decrement: function() {
      this.number--;
    }
  }
});

var title = new Vue({
  el: '#title', 
  data: {
    content : ['from Park Dyel', '<br>now we just start!</br>']
  }
});

