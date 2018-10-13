#include<stdio.h>

int main(void){
  int i, j;
  double s, t;
  double r0, r1;
  double horizon;
  double vertical;
  int ans;
  // 画素値
  int d[2][2] = { {10, 30},
		  {20, 40} };

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

  s = horizon - (int)(horizon+0.5);
  t = vertical - (int)(vertical+0.5);
  if(s < 0){
    s += 1;
  }
  if(t < 0){
    t += 1;
  }

  r0 = (1-s) * d[0][0] + s*d[1][0];
  r1 = (1-s) * d[0][1] + s*d[1][1];

  ans = (int)((1-t) * r0 + t * r1 + 0.5);

  printf("\n＜内挿点の画素値＞\n");
  printf("%d\n", ans);

  return 0;
}
