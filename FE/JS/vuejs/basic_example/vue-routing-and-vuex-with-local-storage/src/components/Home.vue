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
<<<<<<< HEAD
import { getDeviceState } from '../cache'
=======
import { getDeviceState, setDeviceState } from '../cache'
>>>>>>> 47b8135194087ee72e2d597759478667a9975505

export default {
  name: 'Home',
  props: {
    user: String
  },
  mounted() {
    this.$store.commit('deviceStatus', { state:'집이다'})
<<<<<<< HEAD
    console.log(`from cache : ${getDeviceState()}`)
=======
    console.log(`Get Device State : ${getDeviceState()}`)
>>>>>>> 47b8135194087ee72e2d597759478667a9975505
  },
}
</script>
