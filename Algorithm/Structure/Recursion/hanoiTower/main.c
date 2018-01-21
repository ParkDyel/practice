#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to){
  if(n==1){
    printf("���� 1�� %c���� %c�� �Ű���ϴ�.\n", from, to);
  } else {
    hanoi_tower(n-1, from, to, temp);
    printf("���� %d�� %c���� %c�� �Ű���ϴ�.\n", n, from, to);
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
  //         1�� A���� B�� �ű�
  //         2�� A���� C�� �ű�
  //       hanoi_tower(1, A, B, C);
  //         1�� B���� C�� �ű�

  return 0;
}
