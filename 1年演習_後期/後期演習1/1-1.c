//286120 武田佑樹
#include<stdio.h>
int main(void) {
  int max = 0, i, x ;
  for(i = 1; i <= 4; i++) {
    printf("%d番目の数値を入力してください: ", i) ;
    scanf("%d", &x) ;
    if(x <= 0) {
      printf("値は正の数ではありません\n%d番目の数値を入力してください : ", i) ;
      scanf("%d", &x) ;
    }
    if(x > max) {
      max = x ;
    }
  }

  printf("最も大きい値は%dです\n", max) ;

  return 0 ;
}
