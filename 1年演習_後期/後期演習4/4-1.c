#include <stdio.h>
double rectangle(double base, double height) ;

double rectangle(double base, double height) {
  double area ;
  area = base * height ;
  return area ;
}

int main(void) {
  double base, height, area ;

  printf("底辺：") ;
  scanf("%lf", &base) ;
  while(base < 0) {
    printf("0より大きい値を入力してください\n") ;
    printf("底辺：") ;
    scanf("%lf", &base) ;
  }

  printf("高さ：") ;
  scanf("%lf", &height) ;
  while(height < 0) {
    printf("0より大きい値を入力してください\n") ;
    printf("高さ：") ;
    scanf("%lf", &height) ;
  }

  area = rectangle(base, height) ;

  printf("面積：%.2lf\n", area) ;

  return 0 ;
}
