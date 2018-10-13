#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 80000

void quick(int x[], int left, int right);
void bubble(int x_cp[], int num);
void swap(int *a, int *b);

int main(void){
  int i, x[NUM], x_cp[NUM], num = 5000;
  time_t start, end;

    srandom(time(NULL));

    for(i=0; i<num; i++){
      x[i] = random();
    }
    for(i=0; i<num; i++){
      x_cp[i] = x[i];
    }
    
    printf("計数結果の出力形式\n");

    printf("<クイックソート法>\n");
    while(num <= NUM){

      start = clock();
      quick(x, 0, num - 1);
      end = clock();

      printf("計算時間は%.3f秒です\n\n", (float)(end-start) / CLOCKS_PER_SEC);

      num *= 2;
    }

    num = 5000;

    printf("\n<バブルソート法>\n");
    while(num <= NUM){

      printf("データ数:%d\n", num);

      start = clock();
      bubble(x_cp, num);
      end = clock();

      printf("計算時間は%.3f秒です\n\n", (float)(end-start) / CLOCKS_PER_SEC);


      num *= 2;
    }

    return 0;
}
  
 void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quick(int x[], int left, int right){
  int pl = left;
  int pr = right;
  int pivot = x[(pl + pr) / 2];

  while(1){
    while(x[pl] < pivot){
      pl++;
    }
    while(x[pr] > pivot){
      pr--;
    }
    if(pr < pl){
      break;
    }

    swap(&x[pl], &x[pr]);
    pl++;
    pr--;
  }

  if(left < pr){
    quick(x, left, pr);
  }
  if(right > pl){
    quick(x, pl, right);
  }
}

void bubble(int x[], int num){
  int i, j;
  for(i=num-1; i>=0; i--){
    for(j=0; j<i; j++){
      if(x[j] > x[j+1])
        swap(&x[j], &x[j+1]);
    }
  }
}
