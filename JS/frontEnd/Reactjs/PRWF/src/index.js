import React from 'react';
import ReactDOM from 'react-dom';
import { Router, Route, Link, browserHistory } from 'react-router';
import App from './App';
import NotFound from './Pages/NotFound/NotFound';
import Users from './Pages/Users/Users';
import Chats from './Pages/Chats/Chats';
import './index.css';



ReactDOM.render(
  <Router history={browserHistory}>
    <Route path="/" component={App}>
      <Route path="users" component={Users}/>
      <Route path="chats" component={Chats}/>
    </Route>
    <Route path="*" component={NotFound}/>
  </Router>,
   document.getElementById('root'));
