import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

// import ChatListComponent from './Components/ChatList/ChatList.js';
// import UserListComponent from './Components/UserList/UserList.js';
// import NavComponent from './Components/Nav/Nav.js';


class App extends Component {
  constructor(props){
    super(props);

    this.state = {
      visibleTab:'user'
    }
    // this.clickListnerUser = this.clickListner.bind(this, 'user');
    // this.clickListnerChat = this.clickListner.bind(this, 'chat');
  }

  clickListner(listName){
    this.setState({visibleTab:listName})
  }
  render() {
    return (
      <div className="App">
        <h1>App</h1>
          {this.props.children}
      </div>
    );
  }
}

export default App;
