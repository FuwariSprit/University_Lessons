#include<stdio.h>

#define NUM 10
#define WORD 10

typedef struct{
  int id;
  char name[WORD];
  int japan;
  int math;
  int eng;
}STUDENT;

int bin_serch(STUDENT students[], int key);

int main(void){
  int key, num;
  STUDENT students[NUM] = {{6101, "Erika", 98, 76, 85},
			   {6102, "Fumiyasu", 47, 88, 91},
			   {6103, "Rika", 56, 90, 78},
			   {6104, "Shoya", 65, 76, 83},
			   {6105, "Sho", 79, 73, 82},
			   {6106, "Tatsuya", 89, 48, 90},
			   {6107, "Kazunori", 68, 77, 85},
			   {6108, "Katsuhiro", 91, 68, 59},
			   {6109, "Tomohiro", 79, 62, 89},
			   {6110, "Masato", 85, 88, 79}};

  printf("学生番号を入力してください:");
  scanf("%d", &key);

  num = bin_serch(students, key);

  if(num < 0){
    printf("その番号の学生はいません。\n");
  } else {
    printf("%s さん(%d)の成績は,国語%d点,数学%d点,英語%d点,合計%dです。\n",
	   students[num].name, students[num].id, students[num].japan, students[num].math, students[num].eng,
	   students[num].japan + students[num].math + students[num].eng);
  }

  return 0;
}

int bin_serch(STUDENT students[], int key){
  int pl, pr, pc;

  pl = 0; pr = NUM-1;

  while(1){
    if(pr < pl) return -1;
    pc = (pl+pr) / 2;
    if(students[pc].id < key) pl = pc + 1;

    else if(key < students[pc].id) pr = pc - 1;
    else if(students[pc].id == key) return pc;
  }
}
