#include<stdio.h>

int main(void) {

  #define DATA 10

  int i = 1, sum = 0 ;
  int data[DATA] ;

  do{
    printf("データ[No. %2d]を入力してください:", i) ;
    scanf("%d", &data[i]) ;
    i++ ;
  }while(i <= DATA) ;

  printf("\nデータ一覧:\n") ;
  
  for(i = 1 ; i <= DATA ; i++) {
    printf("[No. %2d] %2d\n", i, data[i]) ;
    sum += data[i] ;
  }

  printf("\n合計値 = %2d\n", sum) ;

  return 0 ;

}
