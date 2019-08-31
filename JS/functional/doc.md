# 함수형 프로그래밍이란

## 기본

함수형 프로그래밍은 순수함 함수를 작성하고, 공유된 상태와 변경 가능한 데이터 및 부작용을 피하여 소프트웨어를 작성하는 프로세스이다.

애플리케이션 상태가 공유되고, 객체의 메소드와 사용되는 객체 지향 프로그래밍과 대조는된다

### 장점

보다 간결하고 예측하기 쉬운 코드를 작성할 수 있다.

### Pure Function

함수는 부작용이 없어야 하며, 외부의 상태에 종속되지 않아야 한다.

y= f(x)

### Function composition

합성함수는 말 그대로 두 가지 이상의 함수가 합성되었음을 뜻한다.

f(x), g(x)가 있을 때 f(g(x)) 는 f\*g(x)로 표현할 수 있다.

### 평가와 일급

#### 평가

코드가 계산(Evaluation) 되어 값을 만드는 것

#### 일급

값으로 다룰 수 있다.
변수에 담을 수 있다.
함수의 인자로 사용될 수 있다.
함수의 결과로 사용될 수 있다.

```javascript
const a = 10;
const add10 = (acc) => acc + 10;
const b = add10(a);
```

#### 일급 함수

함수를 값으로 다룰 수 있다.
조합성과 추상화의 도구

```javascript
const add5 = (a) => a + 5;
const deep1 = () => () => 1;
const deep2 = f1();
deep2();
```

#### 고차 함수

함수를 값으로 다루는 함수

##### 함수를 인자로 받아서 실행하는 함수

```javascript
const df = (cb) => cb(1);
const ret = (req) => req + 2;
df(req);

const multiRun = (f, n) => {
  let i = -1;
  while (++i < n) f(i);
};
```

##### 함수를 만들어 리턴하는 함수(클로저)

```javascript
const calc => a => b => a+b;
calc(a=10)(b=10)

```

## 순회와 이터러블:이터레이터 프로토콜

### 리스트 순회

\[ES5\] for i++
\[ES6+\] for of : 선언적

### 이터러블/이터레이터 프로토콜

Symbol.iterator

이터러블 : 이터레이터를 리턴하는 [Symbol.iterator]()를 가진 값
이터레이터 : { value, done } 객체를 리턴하는 next()를 가진 값
이터러블/이터레이터 프로토콜 : 이터러블을 for...of, 전개 연산자 등과 함께 동작하도록한 규약

```javascript
const arr = [1, 2, 3];
for (const el of arr) console.log(el);
arr[Symbol.iterator] = null;
for (const el of arr) console.log(el);

const arr2 = [1, 2, 3];
let iterator = arr2[Symbol.iterator];
iterator.next();
iterator.next();
iterator.next();
iterator.next();
```

```javascript
const iterable = {
  [Symbol.iterator]() {
    let i = 3;
    return {
      next() {
        return i == 0 ? { done: true } : { value: i--, done: false };
      },
      // well formed iterator, 상태값 보관
      [Symbol.iterator]() {
        return this;
      }
    };
  }
};
let iterator = iterable[Symbol.iterator]();
for (const el of iterator) console.log(el);

// 전개연산자
const a = [1, 2];
a[Symbol.iterator] = null;
const b = [...a, ...[3, 4]]; // iterator error!
```

## 제너레이터와 이터레이터

제너레이터: 이터레이너(well formed)이자 이터러블을 생성하는 함수, 모든 로직을 순회 가능하게 만들 수 있음.

```javascript
function* get() {
  yield 1;
  yield 2;
  yield 3;
  return 100; // 순회할 때는 제외됨
}
let iter = gen();
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
```

### odds 예제

```javascript
function* odds(l) {
  for (let i = 0; i < l; i++) {
    if (i % 2) yield i;
  }
}

let iter = odds(10);
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
```

```javascript
function* infinity(i = 0) {
  while (true) {
    yield i++;
  }
}
function* limit(l, iter) {
  for (const a of iter) {
    yield a;
    if (a >= l) return;
  }
}

function* odds(l) {
  for (const a of limit(l, infinity(1))) {
    if (a % 2) yield a;
  }
}

let iter = odds(10);
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());
console.log(iter.next());

// iter 활용 : 구조분해, 나머지 연산자

const [head, ...tail] = odds(5);
console.log(head);
console.log(tail);

const [head, afterHead, ...tail] = odds(5);
console.log(head);
console.log(afterHead);
console.log(tail);
```

## map, filter, reduce

```javascript
const products = [
  { name: 'iphone', price: 15000 },
  { name: 'S10', price: 30000 },
  { name: 'G50', price: 20000 },
  { name: 'V50', price: 70000 },
  { name: 'Q30', price: 26000 }
];
```

### map

```javascript
const map = (f, iter) => {
  let res = [];
  for (const i of iter) {
    res.push(f(i));
  }
  return res;
};

console.log(map((p) => p.name, products));
console.log(map((p) => p.price, products));
```

```javascript
let m = new Map();
m.set('a', 20);
m.set('b', 40);
console.log(new Map(map(([k, a]) => [k, a * 2], m)));
```

### filter

```javascript
const filter = (f, iter) => {
  let res = [];
  for (const i of iter) {
    if (f(i)) res.push(i);
  }
  return res;
};

console.log(...filter((p) => p.price > 20000, products));
console.log(...filter((p) => p.price < 27000, products));
console.log(
  ...filter(
    (n) => n % 2,
    (function*() {
      yield 1;
      yield 2;
      yield 3;
      yield 4;
      yield 5;
    })()
  )
);
```

### reduce

```javascript
const reduce = (f, acc, iter) => {
  if (iter == undefined) {
    iter = acc[Symbol.iterator]();
    acc = iter.next().value;
  }
  for (const i of iter) {
    acc = f(acc, i);
  }
  return acc;
};

const add = (a, b) => a + b;
console.log(reduce(add, 0, [1, 2, 3, 4, 5]));
console.log(reduce(add, [1, 2, 3, 4, 5]));

console.log(
  reduce((total_price, product) => total_price + product.price, 0, products)
);

console.log(reduce(add, map((p) => p.price, products)));
```

## function as value

### go

```JavaScript
const go = (...args) => {

};
  go(
    0,
    a => a+1,
    a => a+10,
    a => a+100,
    log
  );
```
