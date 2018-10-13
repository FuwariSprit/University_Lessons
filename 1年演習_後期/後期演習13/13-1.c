#include<stdio.h>

#define N 10
#define M 10

typedef struct {
  int data[2];
  char id_num[M];
} DATA;

void average_calc(DATA D[], double mean[], int no);
int max_calc(double mean[], int no);

int main(void){
  DATA D[N];
  int i, no, ave_max_no;
  double mean[N];

  do{
    printf("入力データ数を入力して下さい:");
    scanf("%d", &no);
    if(no > 10){
      printf("データ数が10を超えているか負です\n");
    }
  }while(no > 10);

  for(i = 0; i < no; i++){
    printf("データNo.%2dのID番号:", i+1);
    scanf("%s", D[i].id_num);
  }

  printf("各IDのデータを入力して下さい\n");
  for(i = 0; i < no; i++){
    printf("%s\n", D[i].id_num);

    do{
      printf("データNo.%2d-a:", i+1);
      scanf("%d", &D[i].data[0]);
      if(D[i].data[0] > 100){
	printf("入力データが100を超えているか負です\n");
      }
    }while(D[i].data[0] > 100);

    do{
      printf("データNo.%2d-b:", i+1);
      scanf("%d", &D[i].data[1]);
      if(D[i].data[1] > 100){
	printf("入力データが100を超えているか負です\n");
      }
    }while(D[i].data[1] > 100);
  }

  printf("\n入力された値を表示します\n");
  for(i = 0; i < no; i++){
    printf("[%s]", D[i].id_num);
    printf("(a) %3d (b) %3d\n", D[i].data[0], D[i].data[1]);
  }

  average_calc(D, mean, no);

  printf("\n各データ組の平均値は以下の通りです\n");
  for(i = 0; i < no; i++){
    printf("[%s] %.1f\n", D[i].id_num, mean[i]);
  }

  ave_max_no = max_calc(mean, no);

  printf("平均値の最大値は%sの%.1fです\n", D[ave_max_no].id_num, mean[ave_max_no]);

  return 0;
}

void average_calc(DATA D[], double mean[], int no){
  int i;

  for(i = 0; i < no; i++){
    mean[i] = ((double)D[i].data[0] + (double)D[i].data[1]) / 2.0;
  }
}

int max_calc(double mean[], int no){
  int i, max_no = 0;
  double max = mean[0];
  for(i = 1; i < no; i++){
    if(max < mean[i]){
      max = mean[i];
      max_no = i;
    }
  }

    return max_no;
}
