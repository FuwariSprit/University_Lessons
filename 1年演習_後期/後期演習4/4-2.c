#include <stdio.h>
void error_message(void) ;

void error_message(void) {
  printf("入力ミスです！\n") ;
}


int main(void) {
  int x ;
  printf("奇数を入力して下さい：") ;
  scanf("%d", &x) ;
  
  if(x % 2 == 0) {
    error_message() ;
  } else {
    printf("%dは奇数です\n", x) ;
  }

  return 0 ;
}

