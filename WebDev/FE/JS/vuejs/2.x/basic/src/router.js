import Vue from 'vue'
import VueRouter from 'vue-router'

import Main from './components/Main'
import Home from './components/Home'

Vue.use(VueRouter)

const routes = [
    { path : '/', name : 'root', component : Main, children : [
        { path : 'home', name : 'home', component : Home}
    ] },
    { path: '*', redirect : 'home' }
]

export const router = new VueRouter({
    mode: 'history',
    routes  
  })