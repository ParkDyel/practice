<template lang="pug">
  .body_wrapper
    p call me maybe. {{ deviceStatus }}
</template>

<style>
  .body_wrapper {
    text-align: center;
  }
</style>

<script>
  import { mapGetters } from 'vuex'
  // import { mapMutations } from 'vuex'

  export default {
    name: 'About',
    computed: {
      ...mapGetters([
        'deviceStatus'
      ])
    },
    // methods: {
    //   getLocalStorageInteval() {
    //     setInterval(()=>{
    //       if( this.deviceStatus != localStorage.getItem('deviceStatus')){
    //         console.log('change')
    //         this.$store.commit('deviceStatus', {state : localStorage.getItem('deviceStatus')})
    //       }
    //     }, 1000)
    //   }
    // },
    // mounted() {
    //   this.getLocalStorageInteval()
    // },
  }
</script>