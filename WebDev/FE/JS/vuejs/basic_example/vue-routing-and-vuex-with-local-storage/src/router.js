import Vue from 'vue'
import VueRouter from 'vue-router'

import Home from './components/Home.vue'
import About from './components/About.vue'
import NotFound from './components/NotFound.vue'

Vue.use(VueRouter)


const routes = [
  { path: '/home', name: 'home', component : Home },
  { path: '/about', name: 'about', component : About },
  { path: '/*', name: 'notFount', component : NotFound }
]

export const router = new VueRouter({
  // mode: 'history',
  routes  
})