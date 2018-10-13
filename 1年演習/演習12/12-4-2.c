#include<stdio.h>
int main(void) {
  int i , fi, play, cnt, num, ans, sosu ;
  printf("正の数を入力してください\n") ;
  scanf("%d", &play) ;
  
  num = play ;
  cnt = 0 ;
  sosu = 0 ;
  
  for (fi = 1 ; fi <=play ; fi++) {
    
    for (i = 2 ; i < num ; i++) {
      ans = num % i ;
      
      if (ans == 0) {
	sosu = 1 ;
      }
    }
    
    if (sosu == 0) {
      cnt++ ;
    }
    num-- ;
  }

  printf("%dまでの素数の数は%d個です\n", play, cnt) ;
  
  return 0 ;
}
