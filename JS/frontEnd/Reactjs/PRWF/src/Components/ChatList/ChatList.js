import React, { Component } from 'react';
import * as $ from 'jquery';

import './List.css';

function handleSendData(){
  var buf = $("#sendString").val();
  console.log(buf);
}

export default class ChatListComponent extends Component{
  constructor(props){
    super(props);
  }
  render(){
    return(
      <div className={this.props.isActive?'active':'deactive'}>
        <h2>Chat</h2>
          {
            this.props.chats.map((chat) => {
              return <p key={chat.id}>{chat.text}</p>
            })
          }
        <form onSubmit={this.handleSendData}>
          <label>
            <input type="text" name="string" id="sendString"/>
          </label>
          <input type="submit" value="Send" />
        </form>
      </div>
    )
  }
}

ChatListComponent.defaultProps={
  chats:[]
};
