#include<stdio.h>

int main(void) {
  #define DATA 10

  int i = 0, sum = 0, max, min, maxNo, minNo ;
  double ave ;
  int data[DATA] ;

  do{
    printf("データ[No. %2d]を入力してください:", i+1) ;
    scanf("%d", &data[i]) ;
    i++ ;
  }while(i < DATA) ;

  printf("\nデータ一覧:\n") ;

  max = data[0] ;
  min = data[0] ;
  
  for(i = 0 ; i < DATA ; i++) {
    printf("[No. %2d] %d\n", i+1, data[i]) ;
    sum += data[i] ;

    if(max < data[i]) {
      max = data[i] ;
      maxNo = i+1 ;
      
    }
    if(min > data[i]) {
      min = data[i] ;
      minNo = i+1 ;
    }

  }

  ave = (double)sum / (double)DATA ;

  printf("\n平均値 = %.2lf\n", ave) ;
  printf("最大値 = %2d (no.%d)\n", max, maxNo) ;
  printf("最小値 = %2d (no.%d)\n", min, minNo) ;

  return 0 ;
}
