#include<stdio.h>

int gcd(int a, int b) ;
int lcm(int a, int b) ;

int main(void) {

  int a, b, gcdAns, lcmAns ;

  do {
    printf("a:") ;
    scanf("%d", &a) ;
  } while (a <= 0) ;
  do {
    printf("b:") ;
    scanf("%d", &b) ;
  } while (b <= 0) ;

  gcdAns = gcd(a, b) ;
  lcmAns = lcm(a, b) ;

  printf("aとbの最大公約数：%d\n", gcdAns) ;
  printf("aとbの最小公倍数：%d\n", lcmAns) ;

  return 0 ;
}

int gcd(int a, int b) {
  int r, tmp ;

  if(a < b) {
    tmp = a ;
    a = b ;
    b = tmp ;
  }

  r = a % b ;
  while(r != 0) {
    a = b ;
    b = r ;
    r = a % b ;
  }

  return b ;
}

int lcm(int a, int b) {
  int r, x, ans, tmp ;
  
  x = a * b ;
  
  if(a < b) {
    tmp = a ;
    a = b ;
    b = tmp ;
  }

  r = a % b ;
  while(r != 0) {
    a = b ;
    b = r ;
    r = a % b ;
  }

  ans = x / b ;

  return ans ;
}
