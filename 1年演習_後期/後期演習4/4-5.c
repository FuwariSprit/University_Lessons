#include <stdio.h>
#include <math.h>
double distance(int x1, int y1, int x2, int y2) ;


double distance(int x1, int y1, int x2, int y2) {
  double distance ;
  distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) ;
  
  return distance ;
}


int main(void) {
  int x1, x2, y1, y2 ;
  double dis ;

  printf("＜点1＞\n") ;
  printf("x座標：") ;
  scanf("%d", &x1) ;
  printf("y座標：") ;
  scanf("%d", &y1) ;

  printf("＜点2＞\n") ;
  printf("x座標：") ;
  scanf("%d", &x2) ;
  printf("y座標：") ;
  scanf("%d", &y2) ;

  dis = distance(x1, y1, x2, y2) ;

  printf("＜2点間の距離＞\n") ;
  printf("距離：%.6lf\n", dis) ;

  return 0 ;
}
