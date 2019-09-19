const curry = f => (a, ..._) =>  _.length ? f(a, ..._) : (..._) => f(a, ..._);

const map = curry((f, iter) => {
  let res = [];
  for(const i of iter) {
    res.push(f(i));
  }
  return res;
})

const filter = curry((f, iter) => {
  let res = [];
  for(const i of iter){
    if(f(i)) res.push(i);
  }
  return res;
})

const reduce = curry((f, acc, iter) => {
  if (iter == undefined) {
    iter = acc[Symbol.iterator]();
    acc = iter.next().value;
  }
  for(const i of iter){
    acc = f(acc, i)
  }
  return acc;
});

const go = (...args) => reduce((a, f) => f(a), args);

const pipe = (...fs) => (a) => { go(a, ...fs) };
