#include<stdio.h>

int point(int n);

int main(void){
  int n, p;
  
  printf("いくつ買いますか ?:");
  scanf("%d", &n);
  p = point(n);
  printf("ポイントは%d点です.\n", p);
  
  return 0;
}

int point(int n){
  int p;

  if(n == 1){
    p = 10;
  } else if(n >= 2 && n <=10)
    p = 10 + 5 * (n-1);
  else
    p = point(n-1) * 1.1;

  return p;
}
