<template lang="pug">
  .body_wrapper
    p Hello, {{ deviceStatus }}!!
    input(type="button" @click="javaFun" value="JavaFun")
      
</template>

<style>
.body_wrapper {
  text-align: center;
}
</style>

<script>
import { mapGetters } from 'vuex'
import { getDeviceState } from '../cache'

export default {
  name: 'Home',
  props: {
    user: String
  },
  computed: {
    ...mapGetters([
      'deviceStatus'
    ])
  },
  methods: {
    javaFun(){
      console.log('Button Pushed')
      // window.JaJsInterface.echoToast('Hello');
      window.JaJsInterface.setDeviceStatus('Hello');
    }
  },
  mounted() {
    this.$store.commit('deviceStatus', { state:'집이다'})
    console.log(`from cache : ${getDeviceState()}`)
  },
}
</script>
