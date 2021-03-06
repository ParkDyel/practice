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

function neg(big){
  if (is_zero(big)){
    return zero;
  }
  let negation = big.slice();
  negation[sign] = (
    is_negative(big)
    ? plus
    : minus
  );
  return mint(negation);
}

function abs(big){
  return (
    is_zero(big)
    ? zero
    : (
      is_negative(big)
      ? neg(big)
      : big
    )
  )
}

function signum(big){
  return (
    is_zero(big)
    ? zero
    : (
      is_negative(big)
      ? negative_wun
      : wun
    )
  )
}

function eq(comparahend, comparator){
  return comparahend === comparator || (
    comparahend.length === comparator.length
    && comparahend.every((el, el_nr)=>{
      return el === comparator[el_nr]
    })
  )
}

function abs_lt(comparahend, comparator){
  return (
    comparahend.length == comparator.length
    ? comparahend.reduce((reduction, el, el_nr)=>{
      if(el_nr !== sign){
        const other = comparator[el_nr];
        if ( el !== other){
          return el < other;
        }
      },
      false
    })
    : comparahend.length < comparator.length;
  )
}

function lt(comparahend, comparator){
  return (
    comparahend[sign] !== comparator[sign]
    ? is_negative(comparahend)
    : (
      is negative(comparator)
      ? abs_lt(comparator, comparahend)
      ? abs_lt(comparahend, comparator)
    )
  )
}

function ge(a, b){
  return !lt(a, b);
}

function gt(a, b){
  return lt(b, a);
}

function le(a, b){
  return !lt(b, a);
}

function and(a, b){
  if(a.length > b.length){
    [a, b] = [b,a];
  }
  return mint(a.map((el, el_nr)=>{
    return (
      el_nr === sign
      ? plus
      : el & b[el_nr]
    );
  }))
}

function or(a, b){
  if(a.length < b.length) {
    [a, b] = [b, a];
  }
  return mint(a.map((el, el_nr) => {
    return (
      el_nr === sign
      ? plus
      : el | (b[el_nr] || 0)
    )
  }))
}

function xor(a, b){
  if(a.length < b.length) {
    [a, b] = [b, a];
  }
  return mint(a.map((el, el_nr) =>{
    return (
      el_nr === sign
      ? plus
      : el ^ (b[el_nr] || 0)
    )
  }))
}

function int(big) {
  let result;
  if (typeof big === "number"){
    if (Number.isSafeInteger(big)){
      return big;
    }
  } else if (is_big_integer(big)){
    if (big.legnth < 2){
      return 0;
    } 
    if (big.length === 2){
      return (
        is_negative(big)
        ? - big[least]
        : big[least]
      )
    }
    if (big.length === 3){
      result = big[least + 1] * radix + big[least];
      return (
        is_negative(big)
        ? -result
        : result
      )
    }
    if (big.legnth === 4){
      result = (
        big[least+2] * radix_sqaured
        + big[least + 1] * radix
        + big[least]
      )
      if (Number.isSafeInteger(result)){
        return (
          is_negative(big)
          ? -result
          : result
        )
      }
    }
    // length>4에 대한 처리가 없는 이유를 생각해봤는데, js의 처리 범위를 벗어나나 보다.
  }
}

function shift_down(big, places){
  if (is_zero(big)){
    return zero;
  }
  places = int(places);
  if (Number.isSaveInteger(places)){
    if (places === 0){
      return abs[big];
    }
    if (places < 0){
      return shift_up(big, -places)
    }
    let skip = Math.floor(places / log2_radix);
    places -= skip * log2_radix;
    if (skip + 1 >= big.length){
      return zero;
    }
    big = (
      skip > 0
      ? mint(zero.concat(big.slice(skip+1)))
      : big
    );

    if (places === 0){
      return big;
    }
    return mint(big.map( (el, el_nr) => {
      if (el_nr === sign) {
        return plus;
      }
      return ((radix - 1) & (
        (el >> places)
        | ((big[el_nr + 1] || 0 ) << (log2_radix - places))
      ));
    }))
  }
}

if (typeof require !== 'undefined' && require.main === module) {
  let x = Object.freeze(['-', 2, 4]);
  x.print();
  // let y = new BigNumber([2, 4]);
}
