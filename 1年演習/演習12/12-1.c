#include<stdio.h>
int main(void) {
  int i, n, num, MAX ;
  
  i = 1 ;
  num = 0 ;
  MAX = 0 ;

  printf("何個の数を入力しますか:") ;
  scanf("%d", &n) ;

  while(i <= n) {
    printf("%dつめ\n", i) ;
    scanf("%d", &num) ;

    if (num >= MAX) {
      MAX = num ;
    }

    i++ ;
  }

    printf("最も大きい数は%dです\n", MAX) ;

    return 0 ;
}
