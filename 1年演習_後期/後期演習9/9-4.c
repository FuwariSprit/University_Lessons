#include<stdio.h>

void read_score(int score[][3], int n);
void show_score(int score[][3], int subject, int n);

#define NUM 10

int main(void){
  int score[][3], n, subject;

  printf("学生数を入力して下さい（1～10）\n");
  scanf("%d", n);
  
  for(int i = 0; i < n; i++){
    printf("%d番目の学生\n", i);
    read_score(score, n);
  }

  printf("\n得点表を表示する科目を選択して下さい\n");

  
}
