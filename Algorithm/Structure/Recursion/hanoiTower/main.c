#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to){
  if(n==1){
    printf("원판 1을 %c에서 %c로 옮겼습니다.\n", from, to);
  } else {
    hanoi_tower(n-1, from, to, temp);
    printf("원판 %d를 %c에서 %c로 옮겼습니다.\n", n, from, to);
    hanoi_tower(n-1, temp, from, to);
  }
}

int main(int argc, char* argv[]){
  char from = 'A';
  char temp = 'B';
  char to   = 'C';

  hanoi_tower(4, from, temp, to);

  // hanoi_tower(4, A, B, C);
  //   hanoi_tower(3, A, C, B);
  //     hanoi_tower(2, A, C, B);
  //       hanoi_tower(1, A, C, B);
  //         1을 A에서 B로 옮김
  //         2를 A에서 C로 옮김
  //       hanoi_tower(1, A, B, C);
  //         1을 B에서 C로 옮김

  return 0;
}
