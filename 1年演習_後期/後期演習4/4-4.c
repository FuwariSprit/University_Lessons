#include <stdio.h>
void draw_char(int a_number, int s_number) ;


void draw_char(int a_number, int s_number) {
  int i, j ;
  for(i = 1 ; i <= a_number ; i++) {
    printf("*") ;
  }
  for(j = 1 ; j <= s_number ; j++) {
    printf("#") ;
  }

  printf("\n") ;
}


int main(void) {
  int a_num, s_num ;
  printf("アスタリスクの数：") ;
  scanf("%d", &a_num) ;
  while(a_num < 0) {
    printf("アスタリスクの数：") ;
    scanf("%d", &a_num) ;
  }

  printf("シャープの数：") ;
  scanf("%d", &s_num) ;
  while(s_num < 0) {
    printf("シャープの数：") ;
    scanf("%d", &s_num) ;
  }

  draw_char(a_num, s_num) ;

  return 0 ;
}
