import Vue from 'vue'
import VueLocalStorage from 'vue-localstorage'

// Vue.use(VueLocalStorage)
// Or you can specify any other name and use it via this.$ls, this.$whatEverYouWant
Vue.use(VueLocalStorage, {
  name: 'bucket',
  bind: true //created computed members from your variable declarations
})

// Use localStorage from Vue object
// Vue.localStorage.set('someNumber', 123)
// Vue.localStorage.get('someNumber')

// Fallback value if nothing found in localStorage
// Vue.localStorage.get('propertyThatNotExists', 'fallbackValue') // Will return 'fallbackValue' string

// Default type if value isn't registered in localStorage section
// Vue.localStorage.get('property', null, Number)

//register localStorage variables and adds computed variables to local components
//to be used like regular computeds that are stored in the localstorage
export var bucket = new Vue({
  localStorage: {
    deviceStatue: {
      type: String
    },
    // someNumber: {
    //   type: Number,
    // },
    // someBoolean: {
    //   type: Boolean
    // },
    // stringOne: '',
    // stringTwo: {
    //   type: String,
    //   default: 'helloworld!'
    // },
  },
  methods: {
    fetchFromBucket(key) {
      return this.$bucket.get(key)
    },
    saveFromBucket(key, value) {
      this.$bucket.set(key, value);
      return this.fetchFromBucket(key);
    }
  }
})