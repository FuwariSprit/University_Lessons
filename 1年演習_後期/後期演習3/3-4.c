#include<stdio.h>
int main(void) {
  int num, i ;
  printf("正の整数を入力してください．\n") ;
  while(1) {
    printf("整数:") ;
    scanf("%d", &num) ;

    i = 0 ;
    if(num == -1) {
      break ;
    }
    if(num % 2 == 0) {
      i = 1 ;
    }
    if(num % 5 == 0) {
      i = 2 ;
    }
    if(num % 2 == 0 && num % 5 == 0) {
      i = 3 ;
    }

    switch(i) {
    case 0 :
      printf("%dは2と5の倍数ではありません．\n", num) ;
      break ;
    case 1 :
      printf("%dは2の倍数です．\n", num) ;
      break ;
    case 2 :
      printf("%dは5の倍数です．\n", num) ;
      break ;
    case 3 :
      printf("%dは2と5の倍数です．\n", num) ;
      break ;
    }

  }

  return 0 ;
}

    
