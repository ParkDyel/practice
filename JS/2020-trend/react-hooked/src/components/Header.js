/* 
A simple component that renders the app header and accepts a title prop
*/
import React from 'react';

const Header = props => {
  return (
    <header className="App-header">
      <h2>{props.text}</h2>
    </header>
  )
}

export default Header;
