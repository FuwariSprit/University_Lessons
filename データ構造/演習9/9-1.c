#include<stdio.h>

#define NUM 10

void quick(int a[], int left, int right);
void swap(int *x, int *y);

int count = 0;

int main(void){
  int a[NUM] = {7, 2, 5, 3, 1, 10, 6, 8, 9, 4};
  
  printf("<印字出力の形式>\n");
  quick(a, 0, NUM-1);

  printf("\nソート終了:");
  for(int i=0; i<NUM; i++){
    printf("\t%d", a[i]);
  }
  printf("\n");

  return 0;
}

void quick(int a[], int left, int right){
  int i;
  int pl = left;
  int pr = right;
  int pivot;

  pivot = (a[pl] + a[pr]) / 2;
  
  count++;
  printf("\n%d回目の呼び出し\n", count);
  printf("<開始時>\n");
  printf("\t左端の添え字:%d\n", pl);
  printf("\t右端の添え字:%d\n", pr);
  printf("\tピボットの値:%d\n", pivot);
  printf("\t左端〜右端の値:");
  for(i=0; i<NUM; i++){
    printf("\t%d", a[i]);
  }
  printf("\n");

  while(1){
    while(a[pl] < pivot){
      pl++;
    }
    while(pivot < a[pr]){
      pr--;
    }
    if(pr < pl){
      break;
    }
    swap(&a[pl], &a[pr]);
    pl++;
    pr--;
  }

  printf("<ソーティング結果>");
  printf("\t右端〜左端の値:");
  for(i=0; i<NUM-1; i++){
    printf("\t%d", a[i]);
  }
  printf("\n");

  if(left < pr){
    quick(a, left, pr);
  }
  if(pl < right){
    quick(a, pl, right);
  }
}

void swap(int *x, int *y){
  int tmp = *x;
  *x = *y;
  *y = tmp;
}
