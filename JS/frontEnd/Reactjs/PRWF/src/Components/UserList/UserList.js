import React, { Component } from 'react';
import './List.css';

export default class UserListComponent extends Component{
  render(){
    return(
      <div className={this.props.isActive?'active':'deactive'}>
        <h2>UserList</h2>
        <ul>
          {
            this.props.users.map((user) => {
              return <li key={user.id}>{user.name}</li>
            })
          }
        </ul>
      </div>
    )
  }
}

UserListComponent.defaultProps = {
  users:[]
  // isActive:true
};
