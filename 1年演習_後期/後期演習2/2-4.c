#include<stdio.h>
int main(void) {
  int x, y, z, min, max;
  printf("三つの整数を入力してください\n整数（No.1）:") ;
  scanf("%d", &x) ;
  while(x < 0) {
    printf("整数を入力してください\n整数（No.1）:") ;
    scanf("%d", &x) ;
  }
  printf("整数（No.2）:") ;
  scanf("%d", &y) ;
  while(y < 0) {
    printf("整数を入力してください\n整数（No.2）:") ;
    scanf("%d", &y) ;
  }
  printf("整数（No.3）:") ;
  scanf("%d", &z) ;
  while(z < 0) {
    printf("整数を入力してください\n整数（No.3）:") ;
    scanf("%d", &z) ;
  }

  max = x ;
  min = x ;
  if(max <= y) {
    max = y ;
  }
  if(max <= z) {
    max = z ;
  }
  if(min >= y) {
    min = y ;
  }
  if(min >= y) {
    min = z ;
  }

  printf("最大値：%d\n最小値：%d\n", max, min) ;

  return 0 ;
}
