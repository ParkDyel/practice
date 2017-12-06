#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char* argv){

  srand((unsigned)time(NULL));

  static int nDepartment[] = { 11, 18, 23, 78, 88 };
  int nSize = sizeof(nDepartment) / sizeof(nDepartment[0]);

  //학번을 생성한다.
  int nSelectedDepartment = rand() % nSize;
  int nId = rand() % 999 + 1;

  int nNumber = 201700000 + (nDepartment[nSelectedDepartment] * 1000) + nId;
  // char c[10] = { 0 };
  // sprintf(c, "2017%02d%03d", nDepartment[a], b);

  printf("%d", nNumber);

  return;
}