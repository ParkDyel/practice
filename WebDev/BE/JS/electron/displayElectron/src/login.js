var nav = new Vue({
  el: '#fake-nav',
  methods: {
    open: function (which, e) {
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

var modal_submit_register = 'Register';
var modal_submit_password = 'Reset Password';
var modal_submit_login = 'Login';

var modal = new Vue({
  el: '#login-modal',
  data: {
    active: null,

    // Submit button text
    registerSubmit: modal_submit_register,
    passwordSubmit: modal_submit_password,
    loginSubmit: modal_submit_login,

    // Modal text fields
    registerName: '',
    registerEmail: '',
    registerPassword: '',
    loginUser: '',
    loginPassword: '',
    passwordEmail: '',

    // Modal error messages
    registerError: '',
    loginError: '',
    passwordError: '',
  },
  methods: {
    close: function (e) {
      e.preventDefault();
      if (e.target === this.$el) {
        $('#login-modal').removeClass('active');
      }
    },
    flip: function (which, e) {
      e.preventDefault();
      if (which !== this.active) {
        $('#form-' + this.active).removeClass('active');
        $('#form-' + which).addClass('active');
        $('#' + which + '-form').addClass('active');
        $('#' + this.active + '-form').removeClass('active');

        this.active = which;
      }
    },
    submit: function (which, e) {
      e.preventDefault();
      $('#' + which + 'Submit').addClass('disabled');
      var data = {
        form: which
      };

      switch (which) {
        case 'register':
          data.name = this.registerName;
          data.email = this.registerEmail;
          data.password = this.registerPassword;
          this.$set('registerSubmit', 'Registering...');
          break;
        case 'login':
          data.user = this.loginUser;
          data.password = this.loginPassword;
          this.$set('loginSubmit', 'Logging In...');
          break;
        case 'password':
          data.email = this.passwordEmail;
          this.$set('passwordSubmit', 'Resetting Password...')
          break;
      }

      // TODO: submit our `data` variable
    }
  }
});