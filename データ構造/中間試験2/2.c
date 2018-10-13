#include<stdio.h>

#define NUM 5

typedef struct {
  int id;
  char name[10];
  double height;
} STUDENT;

void quick(STUDENT student[], int left, int right);
void swap(STUDENT *a, STUDENT *b);

int main(void){
  int i;
  STUDENT student[NUM] = {
    {101, "斉藤", 176.5},
    {103, "田中", 153.9},
    {100, "中野", 181.2},
    {102, "松本", 165.3},
    {104, "吉田", 168.3}
  };

  printf("[ソート前]\n");
  printf("学生番号\t名前\t身長\t\n");
  for(i=0; i<NUM; i++){
    printf("%d\t%s\t%.1lf\n", student[i].id, student[i].name, student[i].height);
  }

  quick(student, 0, NUM-1);

  printf("\n\n\n[ソート後]\n");
  printf("学生番号\t名前\t身長\t\n");
  for(i=0; i<NUM; i++){
    printf("%d\t%s\t%.1lf\n", student[i].id, student[i].name, student[i].height);
  }

  return 0;
}

void quick(STUDENT student[], int left, int right){
  int pl = left;
  int pr = right;
  double pivot = (student[pl].height + student[pr].height) / 2;

  while(1){
    while(student[pl].height < pivot) pl++;
    while(student[pr].height > pivot) pr--;
    
    if(pr < pl)
      break;
    swap(&student[pl], &student[pr]);
    pl++;
    pr--;
  }
  
  if(left < pl)
    quick(student, left, pr);
  if(pl < right)
    quick(student, pl, right); 
}

void swap(STUDENT *a, STUDENT *b){
  STUDENT tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
}
