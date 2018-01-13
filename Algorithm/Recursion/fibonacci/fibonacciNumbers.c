#include <stdio.h>
#include <time.h>

#include "fibonacciNumbers.h"


int fib_recursion(int n){
  int ret = 0;

  if(n == 0){
    ret = 0;
  } else if(n == 1){
    ret = 1;
  } else {
    ret = fib_recursion(n-1) + fib_recursion(n-2);
  }
  return ret;
};

int fib_repeated(int n){
  int ret = 0;
  if(n < 2){
    ret = n;
  } else {
    int i = 0, temp = 0, current = 1, last = 0;
    for(i = 2; i <= n; i++){
      temp = current;
      current += last;
      last = temp;
    }
    ret = current;
  }
  return ret;
};

clock_t getClock(void){
  return clock();;
}

/* 정말 짧은 시간인 경우에는 아쉽게도 clock()으로 구할 수 없다
*  time()은 말할 것도 없고.
*  이를 구하기 위해선 인라인 어셈블리어를 이용해야 한다고 한다.
*/
float getTime(clock_t startTime){
  return (float) (clock() - startTime) / CLOCKS_PER_SEC ;
}
