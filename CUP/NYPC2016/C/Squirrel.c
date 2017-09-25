/*
* 넥슨아 다람쥐 뿌려줘
* Park Dyel
* 2017.09.23
*/

#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc(), srand(), rand()
#include <stdlib.h>
// timer()
#include <time.h>

int setArraySize(int counter);                                          // scanf arraySize and return it.
char** setArray(int size);                                              // malloc char array(twoDimension)
int setMap(int size, char** address);                                   // scanf data, for in range(0, size)
void getMap(int size, char** address);                                  // printf data in array, for in range(0,size)
int getNumOfChar(char** address, char theChar, int size);               // count PARAM_theChar in array(begin(address), end(address + sizeof(char)*size))
int getNumOfCharacter(char** address, int size);                        // wrapping getNumOfChar(,theChar==c,)
int getNumOfSquirrel(char** address, int size);                         // wrapping getNumOfChar(,theChar==d,)
int setSquirrel(char** address, int numOfChar, int numOfSqui, int size);// calculated need summon, and allocated squirrel.
int checkTheChar(char theChar);                                         // check something in point(x,y)
int freeTwoDimensionalArray(char** address, int size);                  // free(address[]) for in range(0,size)

// flag 
#define CHAR_CHARACTER 'c'
#define CHAR_SQUIRREL 'd'
#define CHAR_DOTGE '.'

const int DEBUG_FLAG = 0;

/* Inner-Rule
* tag [main_] specify variable scope (main)
* tag [temp_] specify variable scope (function)
* tag [ptr_] specify variable type (pointer)
*
*/

int main(int argc, char argv[]){

  printf("Program Working\n\n");

  int main_arraySize = setArraySize(0);
  if(!main_arraySize){
    printf("Plz Check out Usage\n");
    return 0;
  }

  if(DEBUG_FLAG)
    printf("Array Size is %d\n", main_arraySize);

  char** ptr_TwoDimensionalArray = NULL;
  ptr_TwoDimensionalArray = setArray(main_arraySize);
  if(ptr_TwoDimensionalArray == NULL){
    printf("Error:Cannot Allocated Array\n");
    return 0;
  }

  if(DEBUG_FLAG)
    printf("Address : %p\n", ptr_TwoDimensionalArray);

  if (setMap(main_arraySize, ptr_TwoDimensionalArray) != 0){
    printf("Error: setMap");
    return 0;
  }

  getMap(main_arraySize, ptr_TwoDimensionalArray);

  int numOfCharacter = getNumOfCharacter(ptr_TwoDimensionalArray, main_arraySize);
  int numOfSquirrel = getNumOfSquirrel(ptr_TwoDimensionalArray, main_arraySize);
  if(DEBUG_FLAG){
    printf("Number of Character is : %d\n", numOfCharacter);
    printf("Number of Squirrel is : %d\n", numOfSquirrel);
  }

  if(numOfCharacter==0){
    //Nothing
    printf("no one in this maps\n");
  } else if(numOfSquirrel/numOfCharacter>=2){
    //Nothing
    printf("Many Squirrel in this maps\n");
  } else {
    if(DEBUG_FLAG)
      printf("squirrelSummon:Start\n");
    setSquirrel(ptr_TwoDimensionalArray, numOfCharacter, numOfSquirrel, main_arraySize);
    if(DEBUG_FLAG)
      printf("squirrelSummon:Done\n");
  }

  getMap(main_arraySize, ptr_TwoDimensionalArray);

  freeTwoDimensionalArray(ptr_TwoDimensionalArray, main_arraySize);

  if(DEBUG_FLAG)
    printf("Program exit succesfully\n");
  return 0;
}


int setArraySize(int counter){
  /*
  * WARNNING!! This function is Recursive function
  * A lot of code for trainning self purposes.
  */

    // recursive function  Counter 
  if(counter>5){
    return 0;
  }
  if(DEBUG_FLAG)
    printf("Set Array Size:Start\n");

  // sizeOfArray scope is only this function.
  int temp_sizeOfArray;

  //scanf Array Size.
  printf("Plz Insert Map Size(Map Size=InputValue*InputValue)\n");
  scanf("%d", &temp_sizeOfArray);

  if(DEBUG_FLAG)
    printf("Set Array Size:Done\n");

  // function isN need.

  // InputValue must be between 5 ~ 20.
  if( temp_sizeOfArray>20 || temp_sizeOfArray < 5 ){
    temp_sizeOfArray = setArraySize(++counter);
  } else if (temp_sizeOfArray == 0){
    // recursive function  Counter overflow
    temp_sizeOfArray = 0;
  }
  
  // return scanf value.
  return temp_sizeOfArray;
}

char** setArray(int size){
  // memory allocate
  if(DEBUG_FLAG)
    printf("Set Array:Start\n");

  int row=0;
  char **arr=NULL;

  // allocate double char pointer.
  arr = (char **) malloc (sizeof(char*)*size);

  // allocate char pointer each row.
  for(row=0;row<size;row++){
    arr[row]= (char*) malloc (sizeof(char)*(size+1));
    memset(arr[row],'0',size);
    arr[row][size] = '\0';
  }
  if(DEBUG_FLAG)
    printf("Set Array:Done\n");

  // return array pointer.
  return (char**) arr;
}


int setMap(int size, char** address){

  // scanf row.
  if(DEBUG_FLAG)
    printf("Read Map:Start\n");

  int row=0;

  for(row=0; row<size;row++){
    printf("%d - for loop\t", row);
    scanf("%s", address[row]);
    // fgets(ptr, sizeof(size), stdin);
    address[row][size] = '\0';
  }

  if(DEBUG_FLAG)
    printf("Read Map:Done\n");

  return 0;
}

void getMap(int size, char** address){

  // print array.

  if(DEBUG_FLAG)
    printf("get Map:Start\n");

  int row;
  int col;

  for(row=0;row<size;row++){
    for(col=0;col<size;col++){
      //size+1;
      printf("%c", *(*(address+sizeof(char)*row)+sizeof(char)*col));
    }
    printf("\n");
  }
  // for(idx=0; idx<size;idx++){
  //   // printf("%d - for loop\n", idx);
  //   printf("%s", address[idx]);
  // }
  
  if(DEBUG_FLAG)
    printf("get Map:Done\n");

  return;
}

int getNumOfChar(char** address, char theChar, int size){

  // count specify character in array.

  if(DEBUG_FLAG)
    printf("Count \'%c\':Start\n", theChar);

  int row=0;
  int col=0;
  int counter=0;

  for(row=0;row<size;row++){
    for(col=0;col<size+1;col++){
      if(*(*(address+sizeof(char)*row)+sizeof(char)*col) == theChar){
        counter++;
      }
    }
  }

  if(DEBUG_FLAG)
    printf("COUNTER \'%c\':Done, %d\n", theChar, counter);

  // return number of Character in array.
  return counter;
}

int getNumOfCharacter(char** address, int size){
  // wrap getNumOfChar(address,theChar==c,size)
  return getNumOfChar(address, CHAR_CHARACTER, size);
}
int getNumOfSquirrel(char** address, int size){
  // wrap getNumOfChar(address,theChar==d,size)
  return getNumOfChar(address, CHAR_SQUIRREL, size);
}

int setSquirrel(char** address, int numOfChar, int numOfSqui, int size){
  // calculate number of summon and summon it.
  int numOfSummon;

  // if had not enough space for summon squirriel as number of character * 2
  if((numOfChar*3) > (size*size)){
    numOfSummon = (size*size) - numOfChar - numOfSqui;
    printf("Cannot Summon enought:%d\n", numOfSummon-(numOfChar*2));
  } else {
    // need summon number is (number of Character * 2) - number of exist squirrel
    numOfSummon = (numOfChar*2) - numOfSqui;
  }
  
  int countSummon=0;  // count summon be.
  int countIdx;       // count try to summon.

  // printf("need Summon : %d\n", numOfSummon);

  srand(time(NULL));
  for(countIdx=0; numOfSummon!=countSummon;countIdx++){
    printf("Summon Squirrel : %d\n", countSummon+1);
    // random position
    int position = rand()%(size*size);
    int row = position % size;
    int col = position / size;
    if(checkTheChar(*(*(address+sizeof(char)*row)+sizeof(char)*col))){
      *(*(address+sizeof(char)*row)+sizeof(char)*col) = CHAR_SQUIRREL;
      countSummon++;
    }
  }
}

int checkTheChar(char theChar){
  /* check the character, weather is 'd' or 'c'.
  * return 0, if space was used.
  * retrun 1, if space is empty.
  */
  printf("%c", theChar);
  switch(theChar){
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

    // free memory had allocated by malloc

  if(DEBUG_FLAG)
    printf("Free Array:Start\n");

  int row;
  for(row=0;row<size;row++){
    free(address[row]);
  }
  free(address);

  if(DEBUG_FLAG)
    printf("Free Array:Done\n");

  return 0;
}