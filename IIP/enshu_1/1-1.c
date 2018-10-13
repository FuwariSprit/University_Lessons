#include<stdio.h>
#include<stdlib.h>

int main(void){
  FILE *fp;
  int c, i=0;

  fp = fopen("test.bmp","rb");

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
