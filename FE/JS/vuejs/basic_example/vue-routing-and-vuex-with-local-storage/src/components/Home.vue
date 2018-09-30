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
  }
}
</script>
