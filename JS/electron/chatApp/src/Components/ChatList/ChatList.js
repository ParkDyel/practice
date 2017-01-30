import React, { Component } from 'react';
import './List.css';
import firebase from 'firebase';

// const firebaseConfig = {
  // apiKey: 'AIzaSyAguZYIeMIg-_SjNXuO3uDXFcD6IurqdAs',
  // databaseURL:'https://chatappapplication.firebaseio.com/',
// };

export default class ChatListComponent extends Component{

  constructor(props) {
    super(props);

    this.state = { src:this.props.userId, content: '' };

    this.handleChange = this.handleChange.bind(this);
    this.handleSubmit = this.handleSubmit.bind(this);

    // firebase.initializeApp(firebaseConfig);
  };

  handleChange(event) {
    this.setState({value: event.target.value});
  };

  handleSubmit(event){
    console.log( this.state.src + ' : ' + this.state.value);
    event.preventDefault();

    let newPostKey = firebase.database().ref('chats').push().key;

    let postData = {
      src : this.state.src,
      content : this.state.value,
      id : newPostKey
    };


    let updates = {};
    updates['/chats/' + newPostKey] = postData;

    firebase.database().ref().update(updates);
    this.setState({value: ''});
  };

  render(){
    let i=0;

    return(
      <div className={this.props.isActive?'active':'deactive'}>
        <h2>ChatList</h2>
          {
            this.props.chats.map((chat) => {
              return <p key={i++}>{chat.content}</p>
            })
          }
        <form onSubmit={this.handleSubmit}>
          <label>
            <input type="text" value={this.state.value} onChange={this.handleChange} />
          </label>
          <input type="submit" value="Submit" />
        </form>
      </div>
    )
  }
}
