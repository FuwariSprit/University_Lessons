#include<stdio.h>

void read_array(int array[], int n);
void error_data(int element);
void show_array(int array[], int n);
int max_array(int array[], int n);
int min_array(int array[], int n);
double average_array(int array[], int n);


#define N 20
int main(void) {
  int n, array[N], max, min;
  double ave;
    
  printf("データ数を入力してください（1～20）:");
  scanf("%d", &n);
  
  read_array(array, n);

  show_array(array, n);

  max = max_array(array, n);
  min = min_array(array, n);
  ave = average_array(array, n);

  printf("\n最大値は%dです\n", max);
  printf("最小値は%dです\n", min);
  printf("平均値は%.1lfです\n", ave);

  return 0;
}


void read_array(int array[], int n){
  int element;
  for(int i = 0; i < n; i++){
    printf("No.%d:", i+1);
    scanf("%d", &array[i]);
    
    if(array[i] <= 0) {
      element = array[i];
      error_data(element);
      printf("No.%d:", i+1);
      scanf("%d", &array[i]);      
    }
  }
  
}


void error_data(int element) {
  printf("**** 入力ミス:%dは0以下です ****\n", element);  
}


void show_array(int array[], int n) {
  printf("\nデータを表示します\n");

  for(int i = 0; i < n; i++) {
    printf("No.%d:%d\n", i+1, array[i]);
  }
}


int max_array(int array[], int n) {
  int max = array[0];
  for(int i = 0; i < n; i++) {
    if(max < array[i]) {
      max = array[i];
    }
  }

  return max;
}


int min_array(int array[], int n) {
  int min = array[0];
  for(int i = 0; i < n; i++) {
    if(min > array[i]) {
      min = array[i];
    }
  }

  return min;
}


double average_array(int array[], int n) {
  int sum = 0;
  double ave;

  for(int i = 0; i < n; i++) {
    sum += array[i];
  }
  
  ave = (double)sum / (double)n;

  return ave;
}
