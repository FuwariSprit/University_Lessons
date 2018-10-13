#include<stdio.h>

int main(void) {
  int i, max, num ;

  max = 0 ;
  num = 0 ;

  for(i = 1 ; i <= 3 ; i++) {
    printf("%d番目の値 : ", i) ;
    scanf("%d", &num) ;

    if(num <= 0) {
      printf("値は正の数ではありません\n") ;
      printf("%d番目の値 : ", i) ;
      scanf("%d", &num) ;
    }

    if(num >= max) 
      max = num ;

  }

  printf("最も大きい値は%dです\n", max) ;

  return 0 ;
}
