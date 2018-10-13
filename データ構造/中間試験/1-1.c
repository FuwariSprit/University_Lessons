#include<stdio.h>

#define NUM 5

struct student {
  char name[20];
  int id;
  int eng;
  int math;
  int phys;
};

int main(void){
  int i, sum, max, min;
  double avg_sum = 0, avg_sub[3] = {};

  struct student seito[NUM] = {
    {"Abe", 286001, 80, 73, 44},
    {"Igarashi", 286011, 62, 92, 50},
    {"Sato", 286041, 82, 77, 60},
    {"Suzuki", 286091, 74, 85, 94},
    {"Takahashi", 286161, 76, 54, 87}
  };

  for(i=0; i<NUM; i++){
    sum = seito[i].eng + seito[i].math + seito[i].phys;
    printf("%s (%d)の合計点は：%d点\n", seito[i].name, seito[i].id, sum);
    
    if(i == 0){
      max = sum;
      min = sum;
    } else {
      if(max < sum){
	max = sum;
      }
      if(min > sum){
	min =sum;
      }
    }

    avg_sum += (double)sum;
    avg_sub[0] += (double)seito[i].eng;
    avg_sub[1] += (double)seito[i].math;
    avg_sub[2] += (double)seito[i].phys;
  }

  printf("\n------------------------\n");

  printf("合計点の最高は：%d点\n", max);
  printf("合計点の最低は：%d点\n", min);
  printf("合計点の平均は：%.1lf点\n", avg_sum / NUM);
  printf("英語の平均点は：%.1lf点\n", avg_sub[0] / NUM);
  printf("数学の平均点は：%.1lf点\n", avg_sub[1] / NUM);
  printf("物理の平均点は：%.1lf点\n", avg_sub[2] / NUM);

  return 0;
}
