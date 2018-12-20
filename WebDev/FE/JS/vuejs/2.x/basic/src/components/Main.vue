<template lang="pug">
.main
  GNB
  router-view 
</template>

<script>
import GNB from './GNB'

export default {
    components : {
        GNB : GNB
    },
    mounted() {
        this.$router.push({
            "name" : "home"
        })
    },
}
</script>

<style scoped>

</style>
