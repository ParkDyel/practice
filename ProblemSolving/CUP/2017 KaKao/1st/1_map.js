/*
Title   : 비밀지도 합치기!
Date    : 2018.03.30
Author  : Park Dyel
*/

// Input
var line = 6;
var map1 = [46, 33, 33 ,22, 31, 50];
var map2 = [27 ,56, 19, 14, 14, 10];

// Main Function
exports.secretMap = (n, arr1, arr2) => {
  let ret = [];
  arr1 = setMapToBin(n, arr1);
  arr2 = setMapToBin(n, arr2);

  ret = combindMap(n, arr1, arr2);
  ret = setPrintMap(n, ret);

  return ret;
}

// Translate the decimal to binary.
let setMapToBin = (n, arr) => {
  let ret = [];
  for(let idx=0;idx<n;idx++){
    diff      = n - arr[idx].toString(2).length;
    ret[idx]  = Array(diff+1).join('0') + arr[idx].toString(2);
  }
  return ret;
}

// func combindMap and func setPrintMap can be one function.
// Combine two map.
let combindMap = (n, arr1, arr2) => {
  let ret = [];
  for(let idx1=0;idx1<n;idx1++){
    let cur = [];
    for(let idx2=0;idx2<n;idx2++){
      if(arr1[idx1][idx2] ==='1' | arr2[idx1][idx2] === '1')  cur.push('1');
      else                                                    cur.push('0');
    } ret.push(cur.toString().replace(/,/g, ''));
  }
  return ret;
}

// Set map as print mode.
let setPrintMap = (n, arr) => {
  let ret = [];
  for(let idx1=0;idx1<n;idx1++){
    let cul = [];
    for(let idx2=0;idx2<n;idx2++){
      if(arr[idx1][idx2] === '1') cul.push('#');
      else                        cul.push(' ');
    } ret.push(cul.toString().replace(/,/g, ''));
  } 
  return ret;
}

console.log(exports.secretMap(line, map1, map2));