Vue.component('fake-nav', { 
  template:'<div id="fake-nav"><a href="#register" @click="open(1, $event)">Register</a><a href="#login" @click="open(2, $event)">Login</a></div>',
})

var nav = new Vue({
  el: '#header',
  data :function(){
    return {
      name : 0
    }
  },
  methods: {
    open: function (which, e) {
      console.log(e);
      switch(which){
        case 1:
          which='regiter'
          break;
        case 2:
          which='login'
          break;
        defalut:
          break;
      }
      e.preventDefault();
      if (modal.active !== null) {
        $('#form-' + modal.active).removeClass('active');
        $('#' + modal.active + '-form').removeClass('active');
      }
      $('#login-modal').addClass('active');
      $('#form-' + which).addClass('active');
      $('#' + which + '-form').addClass('active');
      modal.active = which;
    },
  }
});