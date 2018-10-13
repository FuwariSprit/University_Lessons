#include<stdio.h>

int main(void) {
  #define DATA 10

  int i = 0, j = 0, serch ;
  int data[DATA], small[DATA], big[DATA], same[DATA] ;

  do{
    printf("データ[No. %d]を入力してください:", i+1) ;
    scanf("%d", &data[i]) ;
    i++ ;
  }while(i < DATA) ;

  printf("\n検索用データを入力してください:") ;
  scanf("%d", &serch) ;

  printf("\n検索結果\n") ;
  printf("検索データ:%d\n", serch) ;


  for(i = 0 ; i < DATA ; i++) {
    if(serch > data[i]) {
      small[j] = data[i] ; 
      j++ ;
    }
  }
  printf("検索データより小さいデータ:") ;
  for(i = 0 ; i < j ; i++) {
    printf("%d", small[i]) ;
    if(i != j-1) {
      printf(",") ;
    }
  }
  printf("\n") ;


  j = 0 ;
  for(i = 0 ; i < DATA ; i++) {
    if(serch == data[i]) {
      same[j] = data[i] ; 
      j++ ;
    }
  }
  printf("検索データと等しいデータ:") ;
  for(i = 0 ; i < j ; i++) {
    printf("%d", same[i]) ;
    if(i != j-1) {
      printf(",") ;
    }
  }
  printf("\n") ;


  j = 0 ;
  for(i = 0 ; i < DATA ; i++) {
    if(serch < data[i]) {
      big[j] = data[i] ; 
      j++ ;
    }
  }
  printf("検索データより大きいデータ:") ;
  for(i = 0 ; i < j ; i++) {
    printf("%d", big[i]) ;
    if(i != j-1) {
      printf(",") ;
    }
  }
  printf("\n") ;

  return 0 ;
}
