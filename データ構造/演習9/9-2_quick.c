#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 20

int n_comp = 0, n_exchange = 0;

void quick(int x[], int left, int right);
void swap(int *a, int *b);

int main(void){
  int i, x[NUM];
  
  srandom(time(NULL));
  for(i=0; i<NUM; i++){
    x[i] = random();
  }

  quick(x, 0, NUM-1);

  printf("データ数:%d\n", NUM);
  printf("比較回数:%d\n", n_comp);
  printf("交換回数:%d\n", n_exchange);

  return 0;
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

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
