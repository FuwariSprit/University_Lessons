#include<stdio.h>
#define NUM 10

typedef struct {
  char name[20];
  double height;
  double weight;
} student;

void insertion(student students[]);

int main(void){
  int i;
  student students[NUM] = {
    {"阿部", 178.5, 72.4},
    {"佐藤", 168.8, 55.5},
    {"鈴木", 163.5, 82.3},
    {"高橋", 185.0, 76.5},
    {"田中", 175.1, 64.2},
    {"友近", 172.3, 68.2},
    {"中島", 179.7, 77.1},
    {"原田", 182.1, 69.3},
    {"安田", 174.5, 58.8},
    {"渡辺", 176.3, 65.6}
  };

  insertion(students);

  printf("氏名\t身長\t体重\n");
  for(i=0; i<NUM; i++){
    printf("%s\t%.1lf\t%.1lf\n",
	   students[i].name, students[i].height, students[i].weight);
  }
  
  return 0;
}

void insertion(student students[]){
  int i, j;
  student tmp[1];
  for(i=1; i<NUM; i++){
    tmp[0] = students[i];
    for(j=i-1; j>=0; j--){
      if(students[j].height < tmp[0].height){
	students[j+1] = students[j];
      }
      else
	break;
    }
      students[j+1] = tmp[0];
  }
}
