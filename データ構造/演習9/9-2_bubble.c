#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 20

int n_comp = 0, n_exchange = 0;

void bubble(int x[], int num);
void swap(int *a, int *b);

int main(void){
  int i, x[NUM];
  
  srandom(time(NULL));
  for(i=0; i<NUM-1; i++){
    x[i] = random();
  }

  bubble(x, NUM);

  printf("データ数:%d\n", NUM);
  printf("比較回数:%d\n", n_comp);
  printf("交換回数:%d\n", n_exchange);

  return 0;
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

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
