#include<stdio.h>
#include<math.h>

typedef struct {
  double x;
  double y;
}Point;

double dt(Point zahyo[3]);

int main(void){
  int i;
  double distance;
  Point zahyo[3];

  printf("3点の座標を入力して下さい\n");
  for(i=0; i<3; i++){
    printf("x: ");
    scanf("%lf", &zahyo[i].x);
    printf("y: ");
    scanf("%lf", &zahyo[i].y);
  }

  distance = dt(zahyo);

  if(distance == -1){
    printf("計算不能\n");
  } else {
    printf("%.2lf\n", distance);
  }

  return 0;
}

double dt(Point zahyo[3]){
  double x_y;
  double y_z;
  double z_x;

  x_y = sqrt(pow((zahyo[0].x - zahyo[1].x), 2) + pow((zahyo[0].y - zahyo[1].y), 2));
  y_z = sqrt(pow((zahyo[1].x - zahyo[2].x), 2) + pow((zahyo[1].y - zahyo[2].y), 2));
  z_x = sqrt(pow((zahyo[2].x - zahyo[0].x), 2) + pow((zahyo[2].y - zahyo[0].y), 2));

  if(x_y + y_z > z_x && y_z + z_x > x_y && z_x + x_y > y_z){
    return x_y + y_z + z_x;
  } else {
    return -1;
  }
}
