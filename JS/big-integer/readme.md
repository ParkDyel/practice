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
