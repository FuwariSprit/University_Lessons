#include<stdio.h>
#include<stdlib.h>

int main(void){
  FILE *fp;
  int c, i, n;

  fp = fopen("test.bmp","wb");

  if(fp == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
  
  printf("ファイルをオープンしました.\n");
  
  c = fgetc(fp);
  
  printf("何バイト書き出しますか:");
  scanf("%d", &n);
  
  printf("0以上255以下の値を%d個入力して下さい.\n", n);
  for(i=0; i<n; i++){
    printf("No.%d : ", i+1);
    scanf("%d", &c);
    fputc(c, fp);
  }
  
  fclose(fp);
  
  printf("ファイルをクローズしました.\n");
  
  return 0;
}
