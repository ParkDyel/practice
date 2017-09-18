#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc(), srand(), rand()
#include <stdlib.h>
// timer()
#include <time.h>

int setArraySize(void);
char** setArray(int size);
int setMap(int size, char** address);
void getMap(int size, char** address);
int freeTwoDimensionalArray(char** address, int size);
int countNumOf(char** address, char theChar, int size);
int countNumOfCharacter(char** address, int size);
int countNumOfSquirrel(char** address, int size);
// float checkRatio(int numOfCharacter, int numOfSquirrel);
int squirrelSummon(char** address, int numOfChar, int numOfSqui, int size);
int checkSpace(char address);

int main(int argc, char argv[]){

  printf("Program Working");

  printf("Plz Input Array size\n");
  int Global_arraySize = setArraySize();
  if(Global_arraySize>20){
    printf("Error:Array Size is bigger than limits\n");
    return 0;
  }
  printf("Array Size is %d\n", Global_arraySize);

  char** ptr_TwoDimensionalArray = NULL;
  ptr_TwoDimensionalArray = setArray(Global_arraySize);
  if(ptr_TwoDimensionalArray == NULL){
    printf("Error:Cannot Allocated Array\n");
    return 0;
  }
  printf("Address : %p\n", ptr_TwoDimensionalArray);

  // printf("print intiailized Array");
  
  // getMap(Global_arraySize, ptr_TwoDimensionalArray);

  if (setMap(Global_arraySize, ptr_TwoDimensionalArray) != 0){
    printf("Error: setMap");
    return 0;
  }

  getMap(Global_arraySize, ptr_TwoDimensionalArray);

  int numOfCharacter = countNumOfCharacter(ptr_TwoDimensionalArray, Global_arraySize);
  int numOfSquirrel = countNumOfSquirrel(ptr_TwoDimensionalArray, Global_arraySize);
  printf("Number of Character is : %d\n", numOfCharacter);
  printf("Number of Squirrel is : %d\n", numOfSquirrel);

  // int ratio = checkRatio(numOfCharacter, numOfSquirrel);
  if(numOfCharacter==0){
    //Nothing
    printf("no one in this maps\n");
  } else if(numOfSquirrel/numOfCharacter>=2){
    //Nothing
    printf("Many Squirrel in this maps\n");
  } else {
    printf("squirrelSummon:Start\n");
    squirrelSummon(ptr_TwoDimensionalArray, numOfCharacter, numOfSquirrel, Global_arraySize);
    printf("squirrelSummon:Done\n");
  }

  getMap(Global_arraySize, ptr_TwoDimensionalArray);

  freeTwoDimensionalArray(ptr_TwoDimensionalArray, Global_arraySize);

  // printf("Program exit succesfully\n");
  // return 0;
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

  int idx=0;
  char **arr=NULL;

  arr = (char **) malloc (sizeof(char*)*size);
  for(idx=0;idx<size;idx++){
    arr[idx]= (char*) malloc (sizeof(char)*(size));
    memset(arr[idx],'0',size);
    arr[idx][size] = '\n';
  }

  printf("Set Array:Done\n");

  return (char**) arr;
}


int setMap(int size, char** address){

  printf("Read Map:Start\n");

  int idx=0;

  for(idx=0; idx<size;idx++){
    printf("%d - for loop\t", idx);
    scanf("%s", address[idx]);
    // fgets(ptr, sizeof(size), stdin);
    address[idx][size] = '\n';
  }

  printf("Read Map:Done\n");

  return 0;
}

void getMap(int size, char** address){

  printf("get Map:Start\n");

  int idx;
  int idx2;

  for(idx=0;idx<size;idx++){
    for(idx2=0;idx2<size+1;idx2++){
      printf("%c", *(*(address+sizeof(char)*idx)+sizeof(char)*idx2));
    }
  }
  // for(idx=0; idx<size;idx++){
  //   // printf("%d - for loop\n", idx);
  //   printf("%s", address[idx]);
  // }
  printf("get Map:Done\n");
}

int countNumOf(char** address, char theChar, int size){

  printf("Count \'%c\':Start\n", theChar);

  int idx=0;
  int idx2=0;
  int counter=0;

  for(idx=0;idx<size;idx++){
    for(idx2=0;idx2<size+1;idx2++){
      if(*(*(address+sizeof(char)*idx)+sizeof(char)*idx2) == theChar){
        counter++;
      }
    }
  }
  printf("COUNTER \'%c\':Done, %d\n", theChar, counter);
  return counter;
}
int countNumOfCharacter(char** address, int size){
  return countNumOf(address, 'c', size);
}
int countNumOfSquirrel(char** address, int size){
  return countNumOf(address, 'd', size);
}

// float checkRatio(int numOfCharacter, int numOfSquirrel){
//   return numOfSquirrel/numOfCharacter;
// }

int squirrelSummon(char** address, int numOfChar, int numOfSqui, int size){
  int numOfSummon = (numOfChar*2) - numOfSqui;
  int countSummon=0;
  int countIdx;

  printf("need Summon : %d\n", numOfSummon);

  srand(time(NULL));
  for(countIdx=0; numOfSummon!=countSummon;countIdx++){
    printf("Summon Squirrel! : %d\n", countSummon);
    int position = rand()%(size*size);
    int idx = position % size;
    int idx2 = position / size;
    if(checkSpace(*(*(address+sizeof(char)*idx)+sizeof(char)*idx2))){
      *(*(address+sizeof(char)*idx)+sizeof(char)*idx2) = 'd';
      countSummon++;
    }
  }
}

int checkSpace(char address){
  printf("%c", address);
  switch(address){
    case 'd':
      return 0;
      break;
    case 'c':
      return 0;
      break;
    default:
      return 1;
      break;
  }
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