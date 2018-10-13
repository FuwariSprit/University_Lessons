#include<stdio.h>
#include<stdlib.h>

#define NUM 4
#define WORD 20

int main(void){
  int i, max = 0;
  char ken[NUM][WORD] = {};
  int zinko_area[NUM][2] = {};
  double mitudo[NUM] = {};
  FILE *fp;
  
  for(i=0; i<NUM; i++){
    printf("%d番目の都道府県は?:", i+1);
    scanf("%s", ken[i]);
    printf("人口は?:");
    scanf("%d", &zinko_area[i][0]);
    printf("面積(㎢)は?:");
    scanf("%d", &zinko_area[i][1]);
  }

  fp = fopen("test.txt", "w");
  for(i=0; i<NUM; i++){
    mitudo[i] = (double)zinko_area[i][0] / (double)zinko_area[i][1];
    if(mitudo[max] < mitudo[i]){
      max = i;
    }
    
    fprintf(fp, "%s\t%d\t%d\t%.1lf\n", ken[i], zinko_area[i][0], zinko_area[i][1], mitudo[i]);
  }
  
  fprintf(fp, "------------------------------------\n");
  fprintf(fp, "最も人口密度が高いのは%sです。\n", ken[max]);
  
  fclose(fp);

  return 0;
  
}
