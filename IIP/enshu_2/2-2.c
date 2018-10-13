#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

int main(void){
  FILE *fp;
  char filename[MAXLEN];
  int c, i, n;

  printf("ファイル名を入力して下さい：");
  scanf("%s", filename);

  fp = fopen(filename,"wb");

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
