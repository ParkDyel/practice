// 새로운 뷰를 정의합니다
var app = new Vue({
  el: '#app', // 어떤 엘리먼트에 적용을 할 지 정합니다
  // data 는 해당 뷰에서 사용할 정보를 지닙니다
  data: {
    name: 'Dyel',
    added:'',
    todos : [
      { todo : 'Follow tutorial.'},
      { todo : 'Concentrate it.'},
      { todo : 'Concentration, again.'}
    ]
  },
  methods:{
    appendTodolist: function(){
      let temp = { todo : this.added + '.'}
      this.todos.push(temp)
    }
  }
});