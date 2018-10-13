//286120 武田佑樹
#include<stdio.h>
int main(void) {
  int x, y ;
  for(x = 9 ; x >= 1 ; x--) {
    for(y = 9 ; y >= 1 ; y--) {
      printf("%2d ", x*y) ;
    }
    printf("\n") ;
  }

  return 0 ;
}
