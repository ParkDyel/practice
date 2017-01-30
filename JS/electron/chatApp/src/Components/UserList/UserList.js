import React, { Component } from 'react';

export default class UserListComponent extends Component{
  render(){
    return(
      <div className={this.props.isActive?'active':'deactive'}>
        <h2>UserList</h2>
        <ul>
          {
            this.props.users.map((user) => {
              return <li key={user.id}>{user.name} : {user.status}</li>
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
