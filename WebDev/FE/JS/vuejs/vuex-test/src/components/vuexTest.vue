<template lang="pug">
.container.df.fdr
  .viewer.fb60.df.fdr
    .title.df.fdc.jcc 직접 state 접근
    .col.df.fdc
      .row state : {{ $store.state }}
      .row userSetting : {{ $store.state.userSetting }}
      .row userSetting.key : {{ $store.state.userSetting.key }}
      .row version : {{ $store.state.version }}
    .title.df.fdc.jcc getter 접근
    .col.df.fdc
      .row getters {{ $store.getters }}
      .row getUserSetting {{ $store.getters.getUserSetting }}
      .row getUserSetting.key : {{ $store.getters.getUserSetting.key }}
      .row getUserKey : {{ $store.getters.getUserKey }}
      .row getVersion : {{ $store.getters.getVersion }}
  .setter.fb40.df.fdc
    .title state 접근
    .wrap.df.fdr
      .btn(@click="incKeyDirect") increment key
      .btn(@click="incVersionDirect") increment ver
    .title setter 접근
    .wrap.df.fdr
      .btn(@click="incKeyGetter") increment key
      .btn(@click="incVersionGetter") increment ver
    .title key 추가
    .wrap.df.fdr
      .btn(@click="setUserPwd") add key direct
      .btn(@click="setUserPwdViaVueSet") add key Vue.set
</template>

<script>
export default {
  name: 'vuexTest',
  methods: {
    incKeyDirect() {
      this.$store.state.userSetting.key += 1;
    },
    incVersionDirect() {
      this.$store.state.version += 1;
    },
    incKeyGetter() {
      this.$store.getters.getUserSetting.key += 1;
    },
    incVersionGetter() {
      this.$store.getters.getVersion += 1;
    },
    setUserPwd() {
      this.$store.state.userSetting.pwd = 1;
    },
    setUserPwdViaVueSet() {
      this.$set(this.$store.state.userSetting, 'pwd', 1);
    }
  }
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
.df {
  display: flex;
}

.df.fdc {
  flex-direction: column;
}
.df.fdr {
  flex-direction: row;
}

.df {
  .jcc {
    justify-content: center;
  }
  .fb40 {
    flex-basis: 40%;
  }
  .fb60 {
    flex-basis: 60%;
  }
}

.title {
  padding: 20px;
  border: 2px solid white;
}

.row {
  text-align: left;
  padding: 20px 20px;
}

.btn {
  margin: 5px;
  padding: 10px;
  border: 2px solid #444;
}
</style>

