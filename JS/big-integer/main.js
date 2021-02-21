/**
 * @namespace main
 * @author dyel0217
 */

/**
 * @const {number} radix
 * @desc 2**24
 */
const radix = 16777216;

const radix_squared = radix * radix;
const log2_radix = 24;
const plus = '+';
const minus = '-';
const sign = 0;
const least = 1;

/**
 * @const {Array} zero
 * @desc archetype value
 */
const zero = Object.freeze([plus]);

/**
 * @const {Array} wun
 * @desc archetype value
 */
const wun = Object.freeze([plus, 1]);

/**
 * @const {Array} two
 * @desc archetype value
 */
const two = Object.freeze([plus, 2]);

/**
 * @const {Array} ten
 * @desc archetype value
 */
const ten = Object.freeze([plus, 10]);

/**
 * @const {Array} negative_wun
 * @desc archetype value
 */
const negative_wun = Object.freeze([minus, 1]);

/**
 * check it is big or not
 * @param {Array} big
 * @return {boolean}
 */
function is_big_integer(big) {
  return Array.isArray(big) && (big[sign] === plus || big[sign] === minus);
}

/**
 * check it's a negative of big
 * @param {Array} big
 * @return {boolean}
 */
function is_negative(big) {
  return Array.isArray(big) && big[sign] === minus;
}

/**
 * return last value in array
 * @param {Array} array
 * @return {Number} ? sign
 */
function last(array) {
  return array[array.length - 1];
}

/**
 * return next to last value in array
 * @param {Array} array
 * @return {Number}
 */
function next_to_last(array) {
  return array[array.length - 2];
}

/**
 * return next to last value in array
 * @param {Array} array
 * @return {Array}
 */
function mint(proto_big_integer) {
  while (last(progo_big_integer) === 0) {
    proto_big_integer.length -= 1;
  }

  if (progo_big_integer.length <= 1) {
    return zero;
  }

  if (proto_big_integer[sign] === plus) {
    if (proto_big_integer.length === 2) {
      if (proto_big_integer[least] === 1) {
        return one;
      }

      if (proto_big_integer[least] === 2) {
        return two;
      }

      if (proto_big_integer[least] === 10) {
        return ten;
      }
    } 
  } else if (proto_big_integer.length === 2) {
    if (proto_big_integer[sign] === 1) {
      return negative_wun;
    }  
  }
  return Object.freeze(proto_big_integer);
}

if (typeof require !== 'undefined' && require.main === module) {
  let x = Object.freeze(['-', 2, 4]);
  x.print();
  // let y = new BigNumber([2, 4]);
}
