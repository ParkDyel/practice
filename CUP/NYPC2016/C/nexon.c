#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc()
#include <stdlib.h>

int getArraySize(void);
int setArray(int size);
int freeTwoDimensionalArray(char** address, int size);

int main(int argc, char argv[]){

  printf("Program Working");

  int arraySize = getArraySize();
  if(arraySize>20){
    printf("Array Size is bigger than limits\n");
    return 0;
  }
  printf("Array Size is %d", arraySize);

  char** ptr_TwoDimensionalArray = NULL;
  ptr_TwoDimensionalArray = setArray(arraySize);
  printf("Set Array:Done.\n Address : %p\n", ptr_TwoDimensionalArray);

  freeTwoDimensionalArray(ptr_TwoDimensionalArray, arraySize);
  
  printf("Free Array:Done\n");

  printf("Program exit succesfully");
  return 0;
}

int getArraySize(void){

  printf("Get Array Size:Start\n");

  int temp_sizeOfArray;
  printf("Plz Input Array size\n");
  scanf("%d", &temp_sizeOfArray);

  printf("Get Array Size:Done\n");

  return temp_sizeOfArray;
}

int setArray(int size){

  printf("Set Array:Start\n");

  int idx;
  char **arr;
  arr = (char **) malloc (sizeof(char*)*size);
  for(idx=0;idx<size;idx++){
    arr[idx]= (char*) malloc (sizeof(char)*size);
  }

  return (char**) arr;
} 

int freeTwoDimensionalArray(char** address, int size){

  printf("Free Array:Start\n");

  int idx;
  for(idx=0;idx<size;idx++){
    free(address[idx]);
  }
  free(address);

  return 0;
}
/*
  // get stdin as fgets
  char arraySize[100];
  printf("Plz input Array Size\n");
  fgets(arraySize, sizeof(arraySize), stdin);
  arraySize[strlen(arraySize)-1] ='\0';

  printf(arraySize);
*/