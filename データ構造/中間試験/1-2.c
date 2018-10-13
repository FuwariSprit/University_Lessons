#include<stdio.h>

#define NUM 4

struct student {
  char name[20];
  int id;
  double height;
  double weight;
};

int main(void){
  int i;
  double hyojun;
  struct student gakusei[NUM];
  
  FILE *fp;
  fp = fopen("test.dat", "w");

  for(i=0; i<NUM; i++){
    printf("%d人目の学生番号は(6桁)？：", i+1);
    scanf("%d", &gakusei[i].id);
    printf("氏名は？：");
    scanf("%s", gakusei[i].name);
    printf("身長(cm)は？：");
    scanf("%lf", &gakusei[i].height);
    printf("体重(kg)は？：");
    scanf("%lf", &gakusei[i].weight);

    hyojun = (gakusei[i].height/100) * (gakusei[i].height/100) * 22.0;
    
    fprintf(fp, "%d %s %.1lf %.1lf %.1lf\n",
	    gakusei[i].id, gakusei[i].name, gakusei[i].height, gakusei[i].weight, gakusei[i].weight - hyojun);
  }

  printf("\nファイル test.dat に出力します。\n");

  fclose(fp);

  return 0;
}
