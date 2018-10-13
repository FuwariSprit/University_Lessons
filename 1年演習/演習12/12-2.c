#include<stdio.h>
int main(void) {
  int i, n ;
  i = 1 ;

  while(i <= 10) {
    n = 1 ;
    
    while(n <= i) {
      printf("*") ;
      n++ ;
    }

    printf("\n") ;
    i++ ;
  }

  return 0 ;
}
