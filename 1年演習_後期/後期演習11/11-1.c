#include<stdio.h>

struct student {
  int id;
  char name[100];
};

int main(void) {
  struct student s = {286000, "Taro"};
  
  printf("学生番号:%d\n", s.id);
  printf("氏名:%s\n", s.name);
  
  return 0;
}
