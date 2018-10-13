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
  int birth = 0;

  fp = fopen(fname, "r");

  fscanf(fp, "%d %d %d\n", &Data.birth_Y, &Data.birth_M, &Data.birth_D);
  fscanf(fp, "%lf %lf\n", &Data.height, &Data.weight);
  fscanf(fp, "%s %s\n", Data.sei, Data.mei);

  printf("氏名は %s %s です\n", Data.sei, Data.mei);

  if(Data.birth_Y < 2017){
    birth -= 1;
  }
  birth += 2017 - Data.birth_Y;

  printf("生年月日は %d年 %d月%d日です (%d)\n",
	 Data.birth_Y, Data.birth_M, Data.birth_D, birth);
  printf("身長は%.1lfcm 体重は%.1lfKg です\n", Data.height, Data.weight);

  fclose(fp);

  return 0;
}
