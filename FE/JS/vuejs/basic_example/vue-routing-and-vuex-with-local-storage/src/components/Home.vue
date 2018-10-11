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
import { getDeviceState } from '../cache'

export default {
  name: 'Home',
  props: {
    user: String
  },
  mounted() {
    this.$store.commit('deviceStatus', { state:'집이다'})
    console.log(`from cache : ${getDeviceState()}`)
  },
}
</script>
