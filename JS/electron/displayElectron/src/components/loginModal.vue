<template>
  <div class="fake-nav">
    <a href="#register" @click="open('register', $event)">Register</a>
    <a href="#login" @click="open(login, $event)">Login</a>
      <div class="user-modal-container" id="login-modal" @click="close">
    <div class="user-modal">
      <ul class="form-switcher">
        <li @click="flip('register', $event)"><a href="" id="register-form">Register</a>
        </li>
        <li @click="flip('login', $event)"><a href="" id="login-form">Login</a>
        </li>
      </ul>
      <div class="form-register" id="form-register">
        <div class="error-message" v-text="registerError"></div>
        <input type="text" name="name" placeholder="Name" v-model="registerName" @keyup.enter="submit('register', $event)">
        <input type="email" name="email" placeholder="Email" v-model="registerEmail" @keyup.enter="submit('register', $event)">
        <input type="password" name="password" placeholder="Password" v-model="registerPassword" @keyup.enter="submit('register', $event)">
        <input type="submit" @click="submit('register', $event)" v-model="registerSubmit" id="registerSubmit">
        <div class="links"> <a href="" @click="flip('login', $event)">Already have an account?</a>
        </div>
      </div>
      <div class="form-login" id="form-login">
        <div class="error-message" v-text="loginError"></div>
        <input type="text" name="user" placeholder="Email or Username" v-model="loginUser" @keyup.enter "submit('login', $event)">
        <input type="password" name="password" placeholder="Password" v-model="loginPassword" @keyup.enter="submit('login', $event)">
        <input type="submit" @click="submit('login', $event)" v-model="loginSubmit" id="loginSubmit">
        <div class="links"> <a href="" @click="flip('password', $event)">Forgot your password?</a>
        </div>
      </div>
      <div class="form-password" id="form-password">
        <div class="error-message" v-text="passwordError"></div>
        <input type="text" name="email" placeholder="Email" v-model="passwordEmail" @keyup.enter="submit('password', $event)">
        <input type="submit" @click="submit('password', $event)" v-model="passwordSubmit" id="passwordSubmit">
      </div>
    </div>
  </div>
  </div>
</template>
<script>
  export default () {
    methods: {
      open: function (which, e) {
        //      console.log(e);
        e.preventDefault();
        if (modal.active !== null) {
          $('#form-' + modal.active).removeClass('active');
          $('#' + modal.active + '-form').removeClass('active');
        }
        $('#login-modal').addClass('active');
        $('#form-' + which).addClass('active');
        $('#' + which + '-form').addClass('active');
        modal.active = which;
      }
    }
  }
</script>