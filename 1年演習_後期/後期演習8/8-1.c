#include<stdio.h>

double average_array(int score[], int n);

#define N 20
int main(void) {

  int score[N];
  int n;
  double ave;

  printf("試験の平均点を計算します，人数を入力してください（1～20）:");
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
    printf("No.%d:", i+1);
    scanf("%d", &score[i]);
  }

  ave = average_array(score, n);
  printf("%d人の平均点は%.1lf点です\n", n, ave);

  return 0;
  
}


double average_array(int score[], int n) {

  int sum = 0;
  double ave;
  
  for(int i = 0; i < n; i++) {
    sum += score[i];
  }

  ave = (double)sum / (double)n;

  return ave;
}
