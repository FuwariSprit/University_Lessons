#include<stdio.h>

#define NUM 10

void ShowList(int data[]);

int main(void){
  int index[NUM] = {2, 4, 6, 8, 10, 12, 14, 16, 18, -1};

  ShowList(index);

  return 0;
}

void ShowList(int data[]){
  printf("リスト:");
  for(int i=0; data[i]!=-1; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}
