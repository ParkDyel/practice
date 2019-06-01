<template lang="pug">
.about
  shared-gnb
</template>


<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';
import SharedGnb from '@/components/sharedGnb.vue'; // @ is an alias to /src

@Component({
  components: {
    'shared-gnb': SharedGnb
  }
})
export default class About extends Vue {}
</script>
