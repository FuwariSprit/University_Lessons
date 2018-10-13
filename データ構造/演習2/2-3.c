#include<stdio.h>

int factorial(int n);

int main(void){
  int n, seki;

  printf("自然数を入力して下さい:");
  scanf("%d", &n);
  seki = factorial(n);
  printf("%dの階乗は, %dです.\n", n, seki);

  return 0;
}

int factorial(int n){
  int tmp;
  
  printf("関数 Factorial(%d)にはいりました.\n", n);
  
  if(n==0){
    tmp = 1;
    printf("関数 Factorial(%d) から出ます: Factorial(%d) = %d\n", n, n, tmp);
  } else
    printf("関数 Factorial(%d) から出ます: Factorial(%d) = %d\n", n, n, tmp = n * factorial(n-1));

  return tmp;
}
