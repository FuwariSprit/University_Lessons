#include<stdio.h>
int main(void) {
  int n, i, score, min = 100, minno, max = 0, maxno ;
  double ave = 0.0 ;
  printf("学生の人数:") ;
  scanf("%d", &n) ;

  for(i = 1 ; i <= n ; i++) {
    printf("No.%d:", i) ;
    scanf("%d", &score) ;

    if(score >= max) {
      max = score ;
      maxno = i ;
    }
    if(score <= min) {
      min = score ;
      minno = i ;
    }
    ave = ave + (double)score ;
  }

  ave = ave / n ;

  printf("平均点は%.1fです\n", ave) ;
  printf("最高点:No.%d君,%d点\n", maxno, max) ;
  printf("最低点:No.%d君,%d点\n", minno, min) ;

  return 0 ;
}
