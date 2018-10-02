<template lang="pug">
  #app
    gnb
    router-view
</template>

<script>
import gnb from './components/GNB.vue'

import { mapGetters } from 'vuex'

export default {
  name: 'app',
  components : {
    gnb: gnb
  },
  computed: {
    ...mapGetters([
      'deviceStatus'
    ])
  },
  methods: {
    customEvtLocalStorageHanddler(e) {
      if (localStorage.getItem(e.detail.field) != this.deviceStatus){
        this.$store.commit('deviceStatus', { state : localStorage.getItem('deviceStatus')})
      }
    }
  },
  mounted() {
    // const evtLocalStorage = new CustomEvent("customLocalStorage", {"bubbles":true, "cancelable":true, "composed":true, "detail":{"field":true, "val":true}})
    document.addEventListener("UserLocalStorage", this.customEvtLocalStorageHanddler)
    // function(e){
    //   console.log("event!")
    // })
  },
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
