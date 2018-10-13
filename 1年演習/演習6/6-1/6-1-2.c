#include<stdio.h>
int main(void) {
  double sintyo, taizyu, BMI ;
  
  printf("身長(cm)を入力してください\n") ;
  scanf("%lf", &sintyo ) ;
  printf("体重(kg)を入力してください\n") ;
  scanf("%lf", &taizyu ) ;

  sintyo = sintyo * 0.01 ;
  BMI = taizyu / (sintyo * sintyo) ;

  if (BMI<20) {
    printf("痩せ気味です\n") ;
  } else if (BMI<24) {
    printf("普通です\n") ;
  } else printf("太り気味です\n") ;

  return 0 ;
}
