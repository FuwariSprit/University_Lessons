#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int birth_Y;
  int birth_M;
  int birth_D;
  double height;
  double weight;
  char sei[10];
  char mei[10];
} Human_Data;

int main(void){
  Human_Data Data;
  char fname[] = "kadai2.txt";
  FILE *fp;

  fp = fopen(fname, "w");

  printf("誕生年:");
  scanf("%d", &Data.birth_Y);
  printf("誕生月:");
  scanf("%d", &Data.birth_M);
  printf("誕生日:");
  scanf("%d", &Data.birth_D);
  fprintf(fp, "%d %d %d\n", Data.birth_Y, Data.birth_M, Data.birth_D);

  printf("\n身長:");
  scanf("%lf", &Data.height);
  printf("体重:");
  scanf("%lf", &Data.weight);
  fprintf(fp, "%lf %lf\n", Data.height, Data.weight);

  printf("\n名字:");
  scanf("%s", Data.sei);
  printf("名前:");
  scanf("%s", Data.mei);
  fprintf(fp, "%s %s\n", Data.sei, Data.mei);

  fclose(fp);

  return 0;
}
