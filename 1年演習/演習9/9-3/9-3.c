#include<stdio.h>
int main(void) {
  int year ;

  printf("年を入力してください\n") ;
  scanf("%d", &year ) ;

  if (year % 4 == 0 && year % 100 != 0) {
    printf("%d年は閏年です\n", year ) ;
  } else if (year % 400 == 0) {
    printf("%d年は閏年です\n", year) ;
  } else {
    printf("%d年は閏年ではありません\n", year) ;
  }

  return 0 ;
}
