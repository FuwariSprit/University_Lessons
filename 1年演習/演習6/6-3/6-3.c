#include <stdio.h>
int main(void) {
  double lx, ly, rx, ry, menseki ;

  printf("左下のx座標とy座標を入力してください\n") ;
  scanf("%lf", &lx) ;
  scanf("%lf", &ly) ;
  printf("右上のx座標とy座標を入力してください\n") ;
  scanf("%lf", &rx) ;
  scanf("%lf", &ry) ;

  menseki = (rx - lx ) ;
  menseki = (ry - ly ) * menseki ;

  printf("面積は%.1fです\n", menseki ) ;

  return 0 ;
}
