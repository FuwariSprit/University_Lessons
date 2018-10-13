#include<stdio.h>
int main(void) {
  int i, n, ans ;
  i = 1 ;

  while(i <= 9) {
    n = 1 ;

    while(n <= 9) {
      ans = i * n ;
      printf("%d ", ans) ;
      n++ ;
    }

    printf("\n") ;
    i++ ;
  }

  return 0 ;
}
