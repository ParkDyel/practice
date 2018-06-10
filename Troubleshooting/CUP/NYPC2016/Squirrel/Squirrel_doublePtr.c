/*

*/


#include <stdio.h>
// strlen()
#include <string.h>
// free(), malloc()
#include <stdlib.h>

int main(int argc, char argv[]){

  printf("Set Array:Start\n");
 
  int idx,idx2;
  int size=4;
  char **arr=NULL;
  
  arr = (char **) malloc (sizeof(char*)*size);

  for(idx=0;idx<size;idx++){
    printf("%d -for loop\t", idx);
    arr[idx]= (char*) malloc (sizeof(char)*(size+1));
    memset(arr[idx],'0',size);
    arr[idx][size] = '\n';
    printf("\n");
  }

  for(idx=0;idx<size;idx++){
    printf("%d -for loop\t", idx);
    printf("%s", arr[idx]);
  }

  for(idx=0;idx<size;idx++){
    scanf("%s", arr[idx]);
    arr[idx][size] = '\n';
  }

  // for(idx=0;idx<size;idx++){
  //   printf("%d -for loop\t", idx);
  //   printf("%s", arr[idx]);
  // }

  printf("OUTPUT\n\n");

  for(idx=0;idx<size;idx++){
    for(idx2=0;idx2<size+1;idx2++){
    // printf("%d", arr);
      printf("%c", *(*(arr+sizeof(char)*idx)+sizeof(char)*idx2));
    }
  }
  
}