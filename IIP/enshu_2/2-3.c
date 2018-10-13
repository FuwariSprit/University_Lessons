#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

int main(void){
  FILE *fp;
  char filename[MAXLEN], filenamecp[MAXLEN];
  unsigned char ary[100];
  int c, n=0, i=0;

  printf("コピー元のファイル名を入力して下さい：");
  scanf("%s", filename);
  printf("コピー先のファイル名を入力して下さい：");
  scanf("%s", filenamecp);  

  fp = fopen(filename, "rb");

  if(fp == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
  printf("%sをオープンしました.\n", filename);

  c = fgetc(fp);
  while(c != EOF){
    ary[n] = c;
    n++;
    c = fgetc(fp);
  }
  
  printf("%sから%d個のデータを配列にコピーしました.\n", filename, n);
  
  fclose(fp);
  printf("%sをクローズしました.\n", filename);

  printf("配列の内容を表示します.\n");

  for(i=0; i<n; i++){
    printf("ary[%d]=%d\n", i, ary[i]);
  }

  fp = fopen(filenamecp, "wb");
  printf("%sをオープンしました.\n", filenamecp);

  for(i=0; i<n; i++){
    fputc(ary[i], fp);
  }
  printf("配列から%dのデータを%sにコピーしました.\n", n, filenamecp);

  fclose(fp);
  printf("%sをクローズしました.\n", filenamecp);

  return 0;
}
