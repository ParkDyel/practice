import React, { Component } from 'react';

export default class NavComponent extends Component{
  render(){
    return (
      <div>
        {this.props.children}
      </div>
    );
  }
}
