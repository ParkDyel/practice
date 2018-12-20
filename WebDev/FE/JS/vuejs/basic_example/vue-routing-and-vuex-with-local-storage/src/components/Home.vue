<template lang="pug">
  .body_wrapper
    p Hello, {{ deviceStatus }}!!
    input(type="button" @click="javaFun" value="JavaFun")
    image-wrapper(:imageDir="pathTable.assets.image" :imgSrc="pathTable.img.logo")
</template>

<style>
.body_wrapper {
  text-align: center;
}
</style>

<script>
import { mapGetters } from 'vuex'
import { getDeviceState } from '../cache'

import pathTable from '../assets/json/path.json'

import ImageWrapper from './ImageWrapper.vue'

export default {
  name: 'Home',
  props: {
    user: String
  },
  data(){
    return {
      pathTable : pathTable
    }
  },
  components : {
    "image-wrapper" : ImageWrapper
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
    // console.log(`from cache : ${getDeviceState()}`)
  },
}
</script>
