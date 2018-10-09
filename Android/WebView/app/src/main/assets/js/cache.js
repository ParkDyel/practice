'use strict';

const CACHE_VAL_JSON_PREFIX = '_JSON_:';

function setCache(key, val) {
  if (localStorage) {
    if (typeof(val) == 'object') {
      val = CACHE_VAL_JSON_PREFIX + JSON.stringify(val);
    }
    localStorage[key] = val;
  }
}

function getCache(key) {
  if (localStorage && key in localStorage) {
    var val = localStorage[key];
    if (val.substr(0, CACHE_VAL_JSON_PREFIX.length) == CACHE_VAL_JSON_PREFIX) {
      val = val.substr(CACHE_VAL_JSON_PREFIX.length);
      val = JSON.parse(val);
    }
    return val;
  }
}

function delCache(key) {
  if (localStorage && key in localStorage) {
    if (key in localStorage) {
      delete localStorage[key];
      return true;
    }
  }
  return false;
}

function getDeviceState() {
  return getCache('DEVICE_STATUS');
}

function setDeviceState(state) {
  console.log(`state : ${state}`);
  setCache('DEVICE_STATUS', state);
  console.log(getDeviceState());
//  return getDeviceState();
}