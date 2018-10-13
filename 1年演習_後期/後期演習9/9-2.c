#include<stdio.h>

#define ROOM_SIZE 4
#define FLORR_SIZE 3

int main(void){
  int i, j, age[FLORR_SIZE][ROOM_SIZE];
  
  printf("住人の年齢を入力して下さい\n");
  for(i = 0; i < FLORR_SIZE; i++){
    printf("<< %d階 >>\n", i+1);
    for(j = 0; j < ROOM_SIZE; j++){
      printf("%d号室:", j+1);
      scanf("%d", &age[i][j]);
    }
  }
  
  printf("\n<< 年齢見取図 >>\n");
  for(i = 3; i > 0; i--){
    printf("[%d階]", i);
    for(j = 0; j < ROOM_SIZE; j++){
      printf("(%d号室)%d歳", j+1, age[i-1][j]);
      if(j==3){
	printf("\n");
      }else{
	printf(" ");
      }
    }
  }
  printf("\n");

  return 0;
}
