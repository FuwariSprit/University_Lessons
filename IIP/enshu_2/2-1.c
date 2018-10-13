#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

int main(void){
  FILE *fp;
  char filename[MAXLEN];
  int c, i=0;

  printf("ファイル名を入力して下さい：");
  scanf("%s", filename);

  fp = fopen(filename,"rb");

  if(fp == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
    
  printf("ファイルをオープンしました.\n");
  
  c = fgetc(fp);
  while(c != EOF){
    printf("%3d\n", c);
    c = fgetc(fp);
    i++;
  }
  
  printf("全部で%dバイト読み込みました.\n", i);
  
  fclose(fp);
  
  printf("ファイルをクローズしました.\n");
  
  return 0;
}
