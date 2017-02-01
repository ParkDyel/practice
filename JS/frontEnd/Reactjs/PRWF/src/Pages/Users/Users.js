import * as _ from 'lodash';
import React, { Component } from 'react';
import firebase from 'firebase';
import UserListComponent from '../../Components/UserList/UserList';

const firebaseConfig = {
  apiKey: 'AIzaSyAguZYIeMIg-_SjNXuO3uDXFcD6IurqdAs',
  databaseURL:'https://chatappapplication.firebaseio.com/',
};

export default class Users extends Component {
  constructor(props) {
    super(props);

    this.state = {
      users: []
    }

    firebase.initializeApp(firebaseConfig);
  }

  componentWillMount() {
    let ref = firebase.database().ref('users');
    let childAddListener = (childSnapshot) => {
      let users = this.state.users;
      users.push(childSnapshot.val());
      this.setState(users);
    }

    let childChangedListener = (childSnapshot) => {
      let users = this.state.users;
      _.forEach(users, (user) => {
        if (user.id === childSnapshot.val().id) {
          user.name = childSnapshot.val().name;
        }
      });
      this.setState(users);
    }

    ref.on('child_added', childAddListener.bind(this));
    ref.on('child_changed', childChangedListener.bind(this));
  }

  render() {
    return (
      <div>
        <h1>Users</h1>
        <UserListComponent users={this.state.users} isActive={true}/>
      </div>
    );
  }
}
