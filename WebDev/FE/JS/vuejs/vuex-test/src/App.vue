<template lang="pug">
.app
  img(alt="Vue logo" src="./assets/logo.png")
  vuex-test
  .link-wrap
    a(href="https://forum.vuejs.org/t/vuex-why-commit-mutations-instead-of-just-set-ing-them/30824/3" target="blank") 왜 mutation을 써야하는가? 패턴, 유지보수, 개발 툴 활용
    a(href="https://vuejs.org/v2/api/#Vue-set" target="blank") Vue.set은 무엇인가? Object에 새로운 키값이 할당될 때 수행되어야 함
</template>

<script>
import VuexTest from './components/vuexTest';

export default {
  name: 'app',
  components: {
    'vuex-test': VuexTest
  }
};
</script>

<style>
html {
  background-color: black;
  color: white;
}
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  margin-top: 60px;
}

.link-wrap {
  display: flex;
  flex-direction: column;
}

.link-wrap a {
  text-decoration: unset;
  color: white;
}

.link-wrap a:hover {
  color: red;
}
</style>
