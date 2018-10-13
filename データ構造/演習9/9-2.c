#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 100

int n_comp, n_exchange;

void quick(int x[], int left, int right);
void bubble(int x_cp[], int num);
void swap(int *a, int *b);

int main(void){
  int i, x[NUM], x_cp[NUM], num = 20;

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

      n_comp = 0;
      n_exchange = 0;
      
      printf("データ数:%d個\n", num);

      quick(x, 0, num - 1);

      printf("比較回数:%d回\n", n_comp);
      printf("交換回数:%d回\n\n", n_exchange);

      num += 20;
    }

    num = 20;

    printf("\n<バブルソート法>\n");
    while(num <= NUM){
      
      n_comp = 0;
      n_exchange = 0;

      printf("データ数:%d\n", num);

      bubble(x_cp, num);

      printf("比較回数:%d\n", n_comp);
      printf("交換回数:%d\n\n", n_exchange);

      num += 20;
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
      n_comp++;
    }
    while(x[pr] > pivot){
      pr--;
      n_comp++;
    }
    if(pr < pl){
      break;
    }

    swap(&x[pl], &x[pr]);
    n_exchange++;
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
      n_comp++;
      if(x[j] > x[j+1]){
        n_exchange++;
        swap(&x[j], &x[j+1]);
      }
    }
  }
}
