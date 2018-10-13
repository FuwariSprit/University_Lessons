#include <stdio.h>
void error_message(void) ;
int get_month(void) ;


int main(void) {
  int month_birth, month_now, month ;

  printf("＜誕生日の月＞\n") ;
  month_birth = get_month() ;

  printf("＜現在の月＞\n") ;
  month_now = get_month() ;

  if(month_birth == month_now) {
    printf("今月が誕生日ですね\n") ;
  } else {
    month = month_birth - month_now ;
    if(month < 0) {
      month = month + 12 ;
    }
    printf("誕生日まであと%dヶ月ですね\n", month) ;
  }

  return 0 ;
}

void error_message(void) {
  printf("入力ミスです！\n") ;
}


int get_month(void) {
  int month ;
  printf("月：") ;
  scanf("%d", &month) ;
  while(month < 1 || month > 12) {
    error_message() ;
    printf("月：") ;
    scanf("%d", &month) ;
  }

  return month ;
}
