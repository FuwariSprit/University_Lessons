#include<stdio.h>
int main(void) {
  int kamoku, points ;

  printf("科目を入力 (1:国語 2:数学 3:英語) :") ;
  scanf("%d", &kamoku) ;

  if (kamoku == 1) {
    printf("点数を入力 :") ;
    scanf("%d", &points) ;
    if (points < 60) {
      printf("国語の成績はDです\n") ;
    } else if (points <= 69) {
      printf("国語の成績はCです\n") ;
    } else if (points <= 79) {
      printf("国語の成績はBです\n") ;
    } else if (points <= 89) {
      printf("国語の成績はAです\n") ;
    } else printf("国語の成績はSです\n") ;

  } else if (kamoku == 2) {
    printf("点数を入力 :") ;
    scanf("%d",&points) ;
    if (points < 60) {
      printf("数学の成績はDです\n") ;
    } else if (points <= 69) {
      printf("数学の成績はCです\n") ;
    } else if (points <= 79) {
      printf("数学の成績はBです\n") ;
    } else if (points <= 89) {
      printf("数学の成績はAです\n") ;
    } else printf("数学の成績はSです\n") ;

  } else if (kamoku == 3) {
    printf("点数を入力 :") ;
    scanf("%d",&points) ;
    if (points < 60) {
      printf("英語の成績はDです\n") ;
    } else if (points <= 69) {
      printf("英語の成績はCです\n") ;
    } else if (points <= 79) {
      printf("英語の成績はBです\n") ;
    } else if (points <= 89) {
      printf("英語の成績はAです\n") ;
    } else printf("英語の成績はSです\n") ;
  }

  return 0 ;
}
