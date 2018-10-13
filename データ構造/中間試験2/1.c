#include<stdio.h>

#define NUM 20

int binary(int x[], int key);

int main(void){
  int key, id;
  int x[NUM] = {1, 2, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 17, 18, 19, 20, 22, 24, 27, 29};
  
  printf("探索する値\t探索結果\tインデックス\n");

  key = 0;
  id = binary(x, key);
  if(id == -1)
    printf("%d\t\t失敗\n", key);
  else
    printf("%d\t\t成功\t\t%d\n", key, id);

  key = 10;
  id = binary(x, key);
  if(id == -1)
    printf("%d\t\t失敗\n", key);
  else
    printf("%d\t\t成功\t\t%d\n", key, id);

  return 0;
}

int binary(int x[], int key){
  int pl, pr, pc;
  pl = 0;
  pr = NUM-1;

  while(1){
    if(pr < pl) return -1;
    
    pc = (pl+pr) / 2;

    if(x[pc] < key)
      pl = pc + 1;
    else if(key < x[pc])
      pr = pc - 1;
    else if(x[pc] == key)
      return pc;
  }
}
