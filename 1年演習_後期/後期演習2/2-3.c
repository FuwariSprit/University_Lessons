#include<stdio.h>
int main(void) {
  int a, b ;
  printf("二つの整数を入力してください\n") ;
  printf("整数A：") ;
  scanf("%d", &a) ;
  while(a < 0) {
    printf("二つの整数を入力してください\n整数a: ") ;
    scanf("%d", &a) ;
  } 
  printf("整数B：") ;
  scanf("%d", &b) ;
  while(b < 0) {
    printf("二つの整数を入力してください\n整数b: ") ;
    scanf("%d", &b) ;
  }
  if(a < b) {
    printf("大きい方の値は%dです\n小さい方の値は%dです\n", b, a) ;
  } else
    if(b < a) {
    printf("大きい方の値は%dです\n小さい方の値は%dです\n", a, b) ;
  } else {
    printf("両方とも%dです\n", a) ;
  }
  
  return 0 ;
}
