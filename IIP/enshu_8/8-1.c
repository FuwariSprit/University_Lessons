#include<stdio.h>

int main(void){
  int i, j;
  // 画素値
  int d[2][2] = { {10, 30},
		  {20, 40} };
  double horizon;
  double vertical;
  int x, y;
  int ans;

  printf("＜使用する4つの画素値＞\n");
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("%d ", d[j][i]);
    }
    printf("\n");
  }
  
  printf("内挿点の座標を入力して下さい\n");
  printf("水平(0.0以上1.0未満) : ");
  scanf("%lf", &horizon);
  printf("垂直(0.0以上1.0未満) : ");
  scanf("%lf", &vertical);

  x = (int)(horizon+0.5);
  y = (int)(vertical+0.5);

  ans = d[y][x];

  printf("\n＜内挿点の画素値＞\n");
  printf("%d\n", ans);
}
