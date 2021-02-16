/**
 * @namespace main
 * @author dyel0217
 */

/**
 * @const {BigNumber} radix
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
 * check it is big or not
 * @param {BigNumber} big
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
 * @class
 * @classdesc Big Number
 */
class BigNumber {
  constructor(_arr) {
    if (
      !Array.isArray(_arr) ||
      !(_arr[sign] === plus || _arr[sign] === minus)
    ) {
      throw TypeError('Value that does not conform to the format.');
    }
    this._value = Object.freeze(_arr);
  }

  /**
   * return value
   * @return {Array}
   */
  get value() {
    return Object.freeze(this._value);
  }

  /**
   * return last elment
   */
  get last() {
    return this._value(this._value.length - 1);
  }

  /**
   * return next to last elment
   */
  get next_to_last() {
    return this._value[this._value.length - 2];
  }

  /**
   * print value
   * FIXME
   */
  print() {
    console.log(
      this._value.reduce((acc, x) => {
        return acc + x;
      }, '')
    );
  }
}

/**
 * @const {BigNumber} zero
 * @desc archetype value
 */
const zero = new BigNumber([plus]);

/**
 * @const {BigNumber} wun
 * @desc archetype value
 */
const wun = new BigNumber([plus, 1]);

/**
 * @const {BigNumber} two
 * @desc archetype value
 */
const two = new BigNumber([plus, 2]);

/**
 * @const {BigNumber} ten
 * @desc archetype value
 */
const ten = new BigNumber([plus, 10]);

/**
 * @const {BigNumber} negative_wun
 * @desc archetype value
 */
const negative_wun = new BigNumber([minus, 1]);

if (typeof require !== 'undefined' && require.main === module) {
  let x = new BigNumber(['-', 2, 4]);
  x.print();
  // let y = new BigNumber([2, 4]);
}
