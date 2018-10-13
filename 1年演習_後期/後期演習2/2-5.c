#include<stdio.h>
int main(void) {
  int x, y ;
  double Atortal = 0.0, Otortal = 0.0, Adiscount = 0.0, Odiscount = 0.0 ;
  printf("りんごの個数：") ;
  scanf("%d", &x) ;
  while(x < 0) {
    printf("りんごの個数: ") ;
    scanf("%d", &x) ;
  }
  printf("みかんの個数：") ;
  scanf("%d", &y) ;
  while(y < 0) {
    printf("みかんの個数: ") ;
    scanf("%d", &y) ;
  }

  Atortal = x * 100 ;
  Otortal = y * 50 ;

  if(x >= 20) {
    Adiscount = Adiscount + 20.0 ;
  } else
    if(x >= 10) {
      Adiscount = Adiscount + 10.0 ;
    }
  if(y >= 10) {
    Odiscount = Odiscount + 20.0 ;
  }
  if(x < 10 && y < 10){
    if(x + y >= 10) {
      Adiscount = Adiscount + 5.0 ;
      Odiscount = Odiscount + 5.0 ;
    }
  }

  Atortal = Atortal - (Atortal * (Adiscount * 0.01)) ;
  Otortal = Otortal - (Otortal * (Odiscount * 0.01)) ;

  printf("＜りんご＞\n単価　：100円\n個数　：%d個\n割引率：%.0f%%\nりんごの合計金額：%.1f円\n", x, Adiscount, Atortal) ;
  printf("＜みかん＞\n単価　：50円\n個数　：%d個\n割引率：%.0f%%\nみかんの合計金額：%.1f円\n", y, Odiscount, Otortal) ;
  printf("＜合計＞\n合計金額：%.1f円\n", Atortal + Otortal) ;

  return 0 ;
}
