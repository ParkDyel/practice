# big-integer

이 프로젝트는 더글라스 크락포드의 "자바스크립크는 왜 그 모양일까?"의 일부를 옮겨 온것입니다.
This project is a part of a translation of Douglas Crockford's "how javascript works".

개인적인 정리글이라 한글로만 표기하려고 합니다.
This is a personal summary, so I will only write it in Korean.

## 왜 이 프로젝트가 있을까요?

JavaScript는 한 가지 자료형으로 모든 수를 표기합니다. 이 자료형은 최대 `9007199254740991`를 나타낼 수 있습니다. 이 이상의 수를 계산하기 위해서는 어떻게 해야 할까요? 더 큰 자료형을 만들어야 할까요? 새로 만들 자료형의 크기는 얼마가 되어야 할까요? 128 bit? 192 bit? 하지만 그 크기가 충분할까요?

언젠가는 그 크기의 한계를 느끼는 계산식이 올지도 모릅니다. 다른 언어에서도 여러가지 자료형이 있지만 결국 자료형의 범위에는 한계가 있어 overflow가 발생합니다.

결국 이를 유연하게 대처하기 위해서는 무한한 자료형이 필요합니다. 다행히 Array를 이용해 이 방법을 시도해 볼 수 있을 것 같습니다. 그렇다면 각 요소의 크기는 몇이 적당할까요? JavaScript의 곱하기와 나누기는 계산값이 53 Bit 내에서만 정확합니다. 그렇다면 53 Bit의 절반인 26 Bit가 배열의 한 요소의 크기로 적당해보입니다(저자는 24 Bit로 크기를 정하였습니다만, 개인적인 취향이라고 합니다).

그럼 큰 수를 표현하는 이 Array를 편의상 Number Chain, 줄여서 NC라고 합시다. NC의 구조는 `[부호, a(*24**0), b(*24**1), c(*24**2), ...]` 로 정의합니다.

이 구조를 다루기 위해 몇개의 상수들과 함수를 정의해봅시다.

```JavaScript
/*
@const string  radix
@description 2**24
*/
const radix = 16777216;
const radix_squared = radix * radix;
const log2_radix = 24;
const plus = "+";
const minus = "-";
const sign = 0;
const least = 1;

function last(array){
  return array[array.length - 1];
}

function next_to_last(array) {
  return array[array.length - 2];
}

```

아래 함수들은 코드를 축약하기 위한 함수입니다.

```JavaScript
const zero = Object.freeze([plus]);
const wun = Object.freeze([plus, 1]);
const two = Object.freeze([plus, 2]);
const ten = Object.freeze([plus, 10]);
const negative_wun = Object.freeze([minus, 1]);
```

확인을 위한 술어 함수입니다.

```JavaScript
function is_big_integer(big){
  return Array.isArray(big) && (big[sign] === plus || big[sign] === minus );
}

function is_negative(big){
  return Array.isArray(big) && big[sign] === minus;
}

function is_positive(big){
  return Array.isArray(big) && big[sign] === plus;
}

function is_zero(big){
  return !Array.isArray(big) || big.lengh < 2;
}
```

mint 함수는 배열의 마지막 요소가 영(0)인 경우 제거합니다. 윗 자리수가 배열의 끝에 있기 때문에, 마지막에 있는 0은 의미가 없습니다. 가능한 상수로 반환하고, 상수 중에 일치하는 것이 없다면 배열을 동결합니다.

```JavaScript
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
```

이제 만들어볼 함수는 부호 바꾸기, 절댓값, 그리고 부호를 추출하는 함수입니다.

```JavaScript
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
```

함수 eq는 두 큰 정수가 동일한 값을 가지는 지 확인합니다.

```JavaScript
function eq(comparahend, comparator){
  return comparahend === comparator || (
    comparahend.length === comparator.length
    && comparahend.every((el, el_nr)=>{
      return el === comparator[el_nr]
    })
  )
}
```

함수 abs_lt는 큰 정수의 절대값이 다른 큰 정수 절대값보다 작은 지 판별합니다. lt 함수는 부호를 포함한 값이 다른 정수 값보다 작은지 봅니다.
```JavaScript
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
```
