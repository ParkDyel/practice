import * as _ from 'lodash';
import React, { Component } from 'react';
import firebase from 'firebase';
import ChatListComponent from '../../Components/ChatList/ChatList';

const firebaseConfig = {
  apiKey: 'AIzaSyAguZYIeMIg-_SjNXuO3uDXFcD6IurqdAs',
  databaseURL:'https://chatappapplication.firebaseio.com/',
};

export default class Chats extends Component {
  constructor(props){
    super(props);

    this.state = {
      chats: [],
      userId:'RuHaMa'
    }

    firebase.initializeApp(firebaseConfig);
  }

  componentWillMount() {
    let ref = firebase.database().ref('chats');
    let childAddListener = (childSnapshot) => {
      let chats = this.state.chats;
      chats.push(childSnapshot.val());
      this.setState(chats);
    }
    console.log(this.state.userId)
    ref.on('child_added', childAddListener.bind(this));
  }

  render(){
    return(
      <div>
        <h1>Chats</h1>
        <ChatListComponent chats={this.state.chats} userId={this.state.userId} isActive={true}/>
      </div>
    )
  }
}
