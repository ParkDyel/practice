<template lang="pug">
  .shared-gnb
    .timer {{ time }}
    .counter 
      .display
        p {{ count }}
      .btn-wrapper
        p(@click='counterIncrement') UP
        p(@click='counterDecrement') DOWN 
</template>

<script lang="ts">
import Vue from 'vue';
import Component from 'vue-class-component';

@Component
export default class SharedGnb extends Vue {
  private count = 0;

  private counterIncrement() {
    this.count++;
  }
  private counterDecrement() {
    this.count--;
  }

  get time() {
    return +new Date();
  }

  private created() {
    console.log(`Created Hook : ${this.count}`);
  }
  private mounted() {
    console.log(`Mounted Hook : ${this.count}`);
  }
  private beforeDestroy() {
    console.log(`beforeDestroy Hook : ${this.count}`);
  }
  private destroyed() {
    console.log(`destroyed Hook : ${this.count}`);
  }
}

// export default Vue.extend({
//   data: {
//     count: 0
//   },
//   computed: {
//     counter(): number {
//       return this.$data.count;
//     }
//   },
//   methods: {
//     increment() {
//       this.$data.count++;
//     },
//     decrement() {
//       this.$data.count--;
//     }
//   },
//   mounted() {
//     window.test = this;
//   }
// });
</script>

<style scoped>
.counter {
  display: flex;
  justify-content: space-evenly;
}

.counter .btn-wrapper {
  display: flex;
  justify-content: space-around;
}
</style>


