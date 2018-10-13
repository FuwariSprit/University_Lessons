#include<stdio.h>
int main (void) {
  int a, b, c, MAX ;

  printf("1つ目の整数を入力してください\n") ;
  scanf("%d", &a) ;
  printf("2つ目の整数を入力してください\n") ;
  scanf("%d", &b) ;
  printf("3つ目の整数を入力してください\n") ;
  scanf("%d", &c) ;

  MAX = a ;

  if (MAX <= b) MAX = b ;
  if (MAX <= c) MAX = c ;

  printf("最も大きい値は%dです\n", MAX) ;

  return 0 ;
}
