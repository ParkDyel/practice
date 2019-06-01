import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    userSetting: {
      key: 1
    },
    version: 1
  },
  getters: {
    getUserSetting: (state) => {
      return state.userSetting
    },
    getUserKey: (state) => {
      return state.userSetting.key
    },
    getVersion: (state) => {
      return state.version
    }
  },
  mutations: {
    setUserSettings: (state, payload) => {
      for (let key in payload) {
        state.userSetting[key] = payload[key]
      }
    },
    setVersion: (state, payload) => {
      state.version = payload
    }
  },
  actions: {

  }
})
