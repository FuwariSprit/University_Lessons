#include<stdio.h>
int main(void) {
  int i, num ;
  printf("*の数を入力してください\n") ;
  scanf("%d", &num) ;

  for (i = 0 ; i <= num ; i++) {
    printf("*") ;
  }

  printf("\n") ;

  return 0 ;
}
