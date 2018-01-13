#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "fibonacciNumbers.h"

int main(int argc, char* argv[]){

  int number,ret ;
  float gap;
  clock_t startTime;

  if(argc != 2){
    printf("USAGE: TEST ${NUMBER}\n");

    return 0;
  }

  number = atoi(argv[1]);

  startTime = getClock();
  ret = fib_recursion(number);
  gap = getTime(startTime);

  printf("Get fibonacci %d as recursion is %d, T : %f\n", number, ret, gap);

  startTime = getClock();
  ret = fib_repeated(number);
  gap = getTime(startTime);

  printf("Get fibonacci %d as repeated is %d, T : %f\n", number, ret, gap);
  return 0;
}