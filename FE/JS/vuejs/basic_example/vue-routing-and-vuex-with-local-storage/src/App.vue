<template lang="pug">
  #app
    gnb
    router-view
</template>

<script>
import gnb from './components/GNB.vue'

export default {
  name: 'app',
  components : {
    gnb: gnb
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
