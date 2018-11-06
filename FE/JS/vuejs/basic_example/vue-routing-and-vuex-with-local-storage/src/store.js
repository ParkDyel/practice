import Vue from 'vue'
import Vuex from 'vuex'
// import createPersistedState from 'vuex-persistedstate'

Vue.use(Vuex)

export const store = new Vuex.Store({
    state : {
      deviceStatus: ''
    },
    getters:{
        deviceStatus (state) {
          return state.deviceStatus;
        },
    },
    mutations: { 
      deviceStatus (state, payload) {
        state.deviceStatus = payload.state;
        localStorage.setItem('deviceStatus', payload.state);
      }
    },
    methods: {
    }
    // plugins: [createPersistedState({

    //   key : '',
    // })],
})