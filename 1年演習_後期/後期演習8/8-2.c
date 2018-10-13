#include<stdio.h>

void reverse_data(int array[], int n);

#define N 10
int main(void) {
  
  int array[N], n;
  
  printf("データ数を入力して下さい（1～10）:");
  scanf("%d", &n);
  printf("データを入力して下さい\n");
  
  for(int i = 0; i < n; i++) {
    printf("No.%d:", i+1);
    scanf("%d", &array[i]);
  }
  
  printf("逆順に並び替えました\n");
  reverse_data(array, n);
  
  return 0;
}


void reverse_data(int array[], int n) {

  int j = 0;

  for(int i = n-1; i >= 0; i--) {
    j++;
    printf("No.%d:%d\n", j, array[i]);
  }
}
