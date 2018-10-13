#include<stdio.h>

int main(void){
  
  #define ARRAY 5
  
  int array[ARRAY] = {5, 4, 3, 2, 1} ;
  int sum = 0, i ;

  for(i = 0 ; i < ARRAY ; i++) {
    sum = sum + array[i] ;
  }

  printf("arrayの合計値 = %d\n", sum) ;

  return 0 ;
}
