#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int id;
  char name[20];
} student;

int main(void){
  int i;
  FILE *fp;

  student gakusei[3] = {
    {286001, "sato"}, {286002, "suzuki"}, {286003, "tanaka"}
  };

  fp = fopen("kadai1.txt", "w");

  for(i=0; i<3; i++){
    fprintf(fp, "学籍番号:%d, 氏名:%s\n", gakusei[i].id, gakusei[i].name);
  }

  fclose(fp);

  return 0;
}
