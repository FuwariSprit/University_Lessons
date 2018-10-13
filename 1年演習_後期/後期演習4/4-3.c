#include <stdio.h>
int get_month(void) ;


int get_month(void) {
  int x ;
  printf("月：") ;
  scanf("%d", &x) ;
  while(x < 1 || x > 12) {
    printf("入力ミスです！\n") ;
    printf("月：") ;
    scanf("%d", &x) ;
  }
  
  return x ;
}


int main(void) {
  int month ;
  printf("誕生日は何月ですか\n") ;
  month = get_month() ;
  printf("あなたは%d月生まれですね\n", month) ;

  return 0 ;
}
