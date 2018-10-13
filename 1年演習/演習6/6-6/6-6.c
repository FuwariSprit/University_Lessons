/* 286120 武田 佑樹 */
#include <stdio.h>
int main(void) {
  double hwidth, height, pi, taiseki ;
  
  pi = 3.14 ;
  
  printf("半径を入力してください\n") ;
  scanf("%lf", &hwidth ) ;
  printf("高さを入力してください\n") ;
  scanf("%lf", &height ) ;

  taiseki = ( hwidth * hwidth * pi ) * height / 3 ;

  printf("円錐の面積は%.2fです\n", taiseki ) ;

  return 0 ;
}
