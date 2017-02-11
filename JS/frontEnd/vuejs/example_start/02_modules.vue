var srcLink = new Vue({
  el: '#srcLink', // 어떤 엘리먼트에 적용을 할 지 정합니다
  // data 는 해당 뷰에서 사용할 정보를 지닙니다
  data: {
    smile: true,
    monologue : "So happy!",
    srcImagefeelsgood: 'https://imgh.us/feelsgood_1.jpg',
    srcImagefeelsbad: 'http://imgh.us/feelsbad.jpg'
  },
  methods: {
    toggleState: function() {
      this.smile = !this.smile
      if(this.smile){
        this.monologue = "So happy!"
      } else {
        this.monologue = "fuck..."
      }
    },   
  },
});