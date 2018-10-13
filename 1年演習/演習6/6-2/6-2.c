#include<stdio.h>
int main(void) {
  int byousu, hour, min, sec ;
  
  printf("秒数は?\n") ;
  scanf("%d", &byousu ) ;

  hour = byousu / 3600 ;
  min = (byousu - (3600 * hour)) / 60 ;
  sec = (byousu - (3600 * hour)) % 60 ;

  printf("%dは%d時間%d分%d秒です\n", byousu, hour, min, sec ) ;

  return 0 ;
}
