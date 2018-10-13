#include<stdio.h>

int main(void) {
  int max, n, x, i ;
  double q_pi, res;

  q_pi = 0.0 ;

  printf("maxを入力してください : ") ;
  scanf("%d", &max) ;
  
  for(n = 0 ; n <= max ; n++) {
    x = 1;
    if(n == 0) x = 1 ;
    else for(i = 0 ; i < n ; i++)
	   x = x * (-1) ;

    res = (double)x / (2 * n + 1) ;
    q_pi = q_pi + res ;
  }

  printf("pi は %.3f です\n", q_pi * 4) ;

  return 0 ;
}
