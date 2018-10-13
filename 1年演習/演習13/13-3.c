#include<stdio.h>

int main(void) {
  int i, num, max, min, nomax, nomin ;
  double ave = 0 ;

  max = 0 ;
  min = 0 ;

  for(i = 1 ; i <= 10 ; i++) {
    printf("No.%d : ", i) ;
    scanf("%d", &num) ;

    while(num < 0 || num > 100) {
      printf("0〜100の範囲を入力してください\n") ;
      printf("No.%d : ", i) ;
      scanf("%d", &num) ;
    }

    if(num <= min || min == 0) {
      min = num ;
      nomin = i ;
    }
    if(num >= max) {
      max = num ;
      nomax = i ;
    }

    ave += num ;
  }

  ave = ave / 10 ;

  printf("平均点は%.1lfです\n", ave) ;
  printf("最高点:No.%2d君 %3d点\n", nomax, max) ;
  printf("最低点:No.%2d君 %3d点\n", nomin, min) ;

  return 0 ;
}
