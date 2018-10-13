#include<stdio.h>
#define NUM 1000

int n_comp = 0, n_exchange = 0;

void bubble(int x[], int num);
void swap(int *a, int *b);

int main(void){
  int i, num, x[NUM];
  
  scanf("%d", &num);
  
  for(i=0; i<num; i++){
    scanf("%d", &x[i]);
  }

  printf("整列前データ\n");
  for(i=0; i<num; i++){
    printf("%4d", x[i]);
  }
  printf("\n");

  bubble(x, num);

  printf("整列後データ\n");
  for(i=0; i<num; i++){
    printf("%4d", x[i]);
  }
  printf("\n");

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
