#include<stdio.h>

typedef struct {
  int id;
  char name[20];
  int math;
  int english;
  int japanese;
} Student;

int main(void){
  Student students[] = {
    {276001, "阿部", 82, 72, 90},
    {276051, "佐藤", 68, 50, 62},
    {276101, "鈴木", 42, 65, 52},
    {276151, "高橋", 92, 34, 46},
    {276201, "渡辺", 50, 70, 74}
  };
  int i, sum;
  double avg = 0;

  printf("\t\t\t成績リスト\n");
  printf("学生番号\t氏名\t数学\t英語\t国語\t合計\n");
  for(i=0; i<5; i++){
    sum = students[i].math + students[i].english + students[i].japanese;
    printf("%d\t\t%s\t%d点\t%d点\t%d点\t%d点\n",
	   students[i].id, students[i].name, students[i].math,
	   students[i].english, students[i].japanese, sum);
  }

  printf("平均点\t\t");
  for(i=0; i<5; i++){
    avg += (double)students[i].math;
  }
  avg /= 5;
  printf("\t%.1lf点", avg);
  
  avg = 0;
  for(i=0; i<5; i++){
    avg += (double)students[i].english;
  }
  avg /= 5;
  printf("\t%.1lf点", avg);
  
  avg = 0;
  for(i=0; i<5; i++){
    avg += (double)students[i].japanese;
  }
  avg /= 5;
  printf("\t%.1lf点", avg);

  printf("\n");

  return 0;
}
