#include<stdio.h>
int main(void) {
  int i , num, ans, sosu ;
  printf("正の整数値を入力してください\n") ;
  scanf("%d", &num) ;

  for (i = 2 ; i < num ; i++) {
    ans = num % i ;
    
    if (ans == 0) {
      sosu = 1 ;
    }
  }

  if (sosu == 0) {
    printf("%dは素数です\n", num) ;
  } else printf("%dは素数ではありません\n", num) ; 

  return 0 ;
}
