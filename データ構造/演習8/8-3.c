#include<stdio.h>
#include<stdlib.h>

#define NUM 100

int Bn_comp = 0, In_comp = 0, n_exchange = 0, n_shift = 0, n_insert = 0;

void bubble(int x[], int num);
void swap(int *a, int *b);
void insertion(int x[], int num);

int main(void){
  int i, num, data_bub[NUM], data_ins[NUM];

  printf("何個の整数を入力しますか？(上限100):");
  scanf("%d", &num);

  for(i=0; i<num; i++){
    data_bub[i] = rand() % num;
    data_ins[i] = data_bub[i];
}

  printf("整列前データ\n");
  for(i=0; i<num; i++){
    printf("%4d", data_bub[i]);
  }
  printf("\n");

  bubble(data_bub, num);
  insertion(data_ins, num);

  printf("バブルソート後データ\n");
  for(i=0; i<num; i++){
    printf("%4d", data_bub[i]);
  }
  printf("\n挿入法後データ\n");
  for(i=0; i<num; i++){
    printf("%4d", data_ins[i]);
  }

  printf("\nバブルソートの比較回数:%d\n", Bn_comp);
  printf("挿入法の比較回数:%d\n", In_comp);
  printf("交換回数:%d\n", n_exchange);
  printf("シフト回数:%d\n", n_shift);
  printf("挿入回数:%d\n", n_insert);

  return 0;
}

void bubble(int x[], int num){
  int i, j;
  for(i=num-1; i>=0; i--){
    for(j=0; j<i; j++){
      Bn_comp++;
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

void insertion(int x[], int num){
  int i, j, tmp;
  for(i=1; i<num; i++){
    tmp = x[i];
    for(j=i-1; j>=0; j--){
      In_comp++;
      if(x[j] > tmp){
        n_shift++;
        x[j+1] = x[j];
      }
      else
        break;
    }
    x[j+1] = tmp;
    n_insert++;
  }
}
