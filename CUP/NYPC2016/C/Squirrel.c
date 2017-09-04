#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc()
#include <stdlib.h>

int setArraySize(void);
char** setArray(int size);
int setMap(int size, char** address);
void getMap(int size, char** address);
int freeTwoDimensionalArray(char** address, int size);


int main(int argc, char argv[]){

  printf("Program Working");

  printf("Plz Input Array size\n");
  int arraySize = setArraySize();
  if(arraySize>20){
    printf("Error:Array Size is bigger than limits\n");
    return 0;
  }
  printf("Array Size is %d\n", arraySize);

  char** ptr_TwoDimensionalArray = NULL;
  ptr_TwoDimensionalArray = setArray(arraySize);
  if(ptr_TwoDimensionalArray == NULL){
    printf("Error:Cannot Allocated Array\n");
    return 0;
  }
  printf("Address : %p\n", ptr_TwoDimensionalArray);

  printf("print intiailized Array");
  
  getMap(arraySize, ptr_TwoDimensionalArray);

  if (setMap(arraySize, ptr_TwoDimensionalArray) != 0){
    printf("Error: setMap");
    return 0;
  }

  printf("print input Map");

  getMap(arraySize, ptr_TwoDimensionalArray);

  freeTwoDimensionalArray(ptr_TwoDimensionalArray, arraySize);

  printf("Program exit succesfully\n");
  return 0;
}


int setArraySize(void){

  printf("Set Array Size:Start\n");

  int temp_sizeOfArray;
  scanf("%d", &temp_sizeOfArray);

  printf("Set Array Size:Done\n");

  return temp_sizeOfArray;
}

char** setArray(int size){

  printf("Set Array:Start\n");

  int idx;
  char **arr;

  arr = (char **) malloc (sizeof(char*)*size);
  for(idx=0;idx<size;idx++){
    arr[idx]= (char*) malloc (sizeof(char)*(size+1));
    memset(arr[idx],'0',size);
    arr[idx][size] = '\n';
  }

  printf("Set Array:Done\n");

  return (char**) arr;
}


int setMap(int size, char** address){

  printf("Read Map:Start\n");

  int idx=0;
  char* ptr = NULL;
  ptr = *address;

  for(idx=0; idx<size;idx++){
    printf("%d - for loop\t", idx);
    scanf("%s", ptr);
    // fgets(ptr, sizeof(size), stdin);
    ptr[size] ='\n';
    ptr += sizeof(char) * size;
  }

  printf("Read Map:Done\n");

  return 0;
}

void getMap(int size, char** address){

  printf("get Map:Start\n");

  int idx=0;
  char* ptr = NULL;
  ptr = *address;

  for(idx=0; idx<size;idx++){
    printf("%d - for loop\n", idx);
    printf("%s", ptr);
    ptr += sizeof(char) * size;
  }

  printf("get Map:Done\n");
}

int freeTwoDimensionalArray(char** address, int size){

    printf("Free Array:Start\n");

    int idx;
    for(idx=0;idx<size;idx++){
      free(address[idx]);
    }
    free(address);

    printf("Free Array:Done\n");

    return 0;
}