#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc()
#include <stdlib.h>

int getArraySize(void);
int setArray(int size);
int freeTwoDimensionalArray(int address, int size);

int main(int argc, char argv[]){

  printf("Program Working");

  printf("Get Array Size:Start\n");
  int arraySize = getArraySize();
  if(arraySize>20){
    printf("Array Size is bigger than limits\n");
    return 0;
  }
  printf("Get Array Size:Done\n");
  printf("Array Size is %d", arraySize);

  printf("Set Array:Start\n");
  int ptr_TwoDimensionalArray = setArray(arraySize);
  printf("Set Array:Done.\n Address : %p\n", ptr_TwoDimensionalArray);

  printf("Free Array:Start\n");
  freeTwoDimensionalArray(ptr_TwoDimensionalArray, arraySize);
  printf("Free Array:Done\n");

  printf("Program exit succesfully");
  return 0;
}

int getArraySize(void){
  int temp_sizeOfArray;
  printf("Plz Input Array size\n");
  scanf("%d", &temp_sizeOfArray);

  return temp_sizeOfArray;
}

int setArray(int size){
  int idx;
  char **arr;
  arr = (char **) malloc (sizeof(char*)*size);
  for(idx=0;idx<size;idx++){
    arr[idx]= (char*) malloc (sizeof(char)*size);
  }

  return arr
} 

int freeTwoDimensionalArray(int address, int size){
  int idx;
  for(idx=0;idx<size;idx++){
    free(address[idx]);
  }
  free(address);
}
/*
  // get stdin as fgets
  char arraySize[100];
  printf("Plz input Array Size\n");
  fgets(arraySize, sizeof(arraySize), stdin);
  arraySize[strlen(arraySize)-1] ='\0';

  printf(arraySize);
*/