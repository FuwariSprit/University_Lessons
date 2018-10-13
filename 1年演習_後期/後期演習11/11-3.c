#include<stdio.h>

#define N 5

struct student {
  int id, math, english, physics, sum;
};

int main(void) {
  struct student s[N];
  int i, max, min;
  double ave = 0.0;
  
  for(i = 0; i < N; i++) {
    printf("%d人目の学生番号は?:", i+1);
    scanf("%d", &s[i].id);
    printf("数学の点数は?:");
    scanf("%d", &s[i].math);
    printf("英語の点数は?:");
    scanf("%d", &s[i].english);
    printf("物理の点数は?:");
    scanf("%d", &s[i].physics);
    s[i].sum = s[i].math + s[i].english + s[i].physics;
  }
  
  max = s[0].sum;
  for(i = 0; i < N; i++) {
    if(max < s[i].sum) {
      max = s[i].sum;
    }
  }
  
  min = s[0].sum;
  for(i = 0; i < N; i++) {
    if(min > s[i].sum) {
      min = s[i].sum; 
    }
  }

  for(i = 0; i < N; i++) {
    ave += (double)s[i].sum;
    if(i == N-1) {
      ave = ave / N;
    }
  }

  printf("\n学生番号 数学 英語 物理 合計\n");
  for(i = 0; i < N; i++) {
    printf("  %3d  %3d  %3d  %3d  %3d\n", s[i].id, s[i].math, s[i].english, s[i].physics, s[i].sum);
  }

  printf("最高点は%d点\n", max);
  printf("最低点は%d点\n", min);
  printf("平均点は%.2f点\n", ave);

  return 0;
}
