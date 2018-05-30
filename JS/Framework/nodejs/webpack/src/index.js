import _ from 'lodash';

var component = () => {
    var e = document.createElement('div');
      e.innerHTML = _.join(['Hello', 'webpack'], ' ');
      return e;
  }

var setMap = () => {
    var e = document.createElement('div')
}

document.body.appendChild(component());