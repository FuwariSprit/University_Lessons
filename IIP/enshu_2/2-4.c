#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

int main(void){
  FILE *fp1, *fp2;
  char filename1[MAXLEN], filename2[MAXLEN];
  int c1, c2, n=0, m=0; 

  printf("ファイル名を2つ入力して下さい.\n");
  scanf("%s", filename1);
  scanf("%s", filename2);

  fp1 = fopen(filename1, "rb");
  fp2 = fopen(filename2, "rb");

  if(fp1 == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
  printf("%sをオープンしました.\n", filename1);

  if(fp2 == NULL){
    printf("ファイルをオープンできません.\n");
    exit (1);
  }
  printf("%sをオープンしました.\n", filename2);

  c1 = fgetc(fp1);
  c2 = fgetc(fp2);
  while(c1 != EOF || c2 != EOF){
    n++;
    c1 = fgetc(fp1);
    c2 = fgetc(fp2);

    if(c1 == c2){
      m++;
    }
  }

  if(n == m){
    printf("%sと%sは同一です.\n", filename1, filename2);
  } else {
    printf("%sと%sは異なります.\n", filename1, filename2);
  }

  fclose(fp1);
  printf("%sをクローズしました.\n", filename1);
  fclose(fp2);
  printf("%sをクローズしました.\n", filename2);


  return 0;
}
