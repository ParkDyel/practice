<template lang="pug">
    .body_wrapper
        p Hello, {{ user }}!!
</template>

<style>
.body_wrapper {
    text-align: center;
}
</style>

<script>
import { getDeviceState, setDeviceState } from '../cache'

export default {
  name: 'Home',
  props: {
    user: String
  },
  mounted() {
    this.$store.commit('deviceStatus', { state:'집이다'})
    console.log(`Get Device State : ${getDeviceState()}`)
  },
}
</script>
