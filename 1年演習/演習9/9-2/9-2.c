#include<stdio.h>
int main(void) {
  int n ;
  
  printf("数値を入力してください\n") ;
  scanf("%d", &n ) ;

  if (n % 3 == 0 && n >= 0) {
    printf("Y\n") ;
  } else {
    printf("N\n") ;
  }

  return 0 ;
}
