#include<stdio.h>

int fibonacchi(int n);

int main(void){
  int n, ans;

  printf("n番目のフィボナッチ数を求めます。\n");
  printf("nの値は?：");
  scanf("%d", &n);

  ans = fibonacchi(n);
  
  printf("n番目のフィボナッチ数は%dです。\n", ans);

  return 0;
}

int fibonacchi(int n){
  int ans;

  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  ans = fibonacchi(n-1) + fibonacchi(n-2);

  return ans;
}
