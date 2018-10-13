// 286120 武田佑樹
#include <stdio.h>
int main(void) {
  int i = 2, n, a, count = 0 ;

  printf("正の数を入力: ") ;
  scanf("%d", &n) ;
  while(i <= n) {
    a = 2 ;
    while( (i % a != 0) && (i > a) ) {
      a++ ;
    }
    if (i == a) {
      count++ ;
    }
    i++ ;
  }
  printf("素数の数は%d個です\n", count) ;
  return 0 ;
}
