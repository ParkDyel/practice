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
export default {
  name: 'Home',
  props: {
    user: String
  },
  mounted() {
    this.$store.commit('deviceStatus', { state:'집이다'})
  },
}
</script>
