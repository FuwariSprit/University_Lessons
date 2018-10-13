#include<stdio.h>
int main(void) {
  int big, small, sum = 0, i ;
  printf("2つの整数間の合計を求めます．\n整数を入力してください．\n") ;
  printf("小さいほうの整数:") ;
  scanf("%d", &small) ;
  printf("大きいほうの整数:") ;
  scanf("%d", &big) ;
  
  i = small ;
  while(i <= big) {
    sum = sum + i ;
    i++ ;
  }

  printf("合計:%d\n", sum) ;

  return 0 ;
}
