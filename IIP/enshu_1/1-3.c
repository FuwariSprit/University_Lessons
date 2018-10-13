#include<stdio.h>
#include<stdlib.h>

int main(void){
  FILE *fp;
  unsigned char ary[100];
  int c, n=0, i=0;

  fp = fopen("test.bmp", "rb");

  if(fp == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
  printf("読み込み用ファイルをオープンしました.\n");

  c = fgetc(fp);
  while(c != EOF){
    ary[n] = c;
    n++;
    c = fgetc(fp);
  }
  
  printf("%d個のデータを読み込み,配列に格納しました.\n", n);
  
  fclose(fp);
  printf("読み込み用ファイルをクローズしました.\n");

  printf("配列の内容を表示します.\n");

  for(i=0; i<n; i++){
    printf("ary[%d]=%d\n", i, ary[i]);
  }

  fp = fopen("testcp.bmp", "wb");
  printf("書き出し用ファイルをオープンしました.\n");

  for(i=0; i<n; i++){
    fputc(ary[i], fp);
  }
  printf("配列に格納されていた%d個のデータを書き出しました.\n", n);

  fclose(fp);
  printf("書き出し用ファイルをクローズしました.\n");

  return 0;
}
