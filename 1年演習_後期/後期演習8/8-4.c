#include<stdio.h>

void read_vector3D(double vector[]);
void outer_product3D(double vector1[], double vector2[], double vector3[]);
double inner_product3D(double vector1[], double vector2[]);

#define N 3
int main(void) {

  double vector1[N], vector2[N], vector3[N], inner_data;

  printf("ベクトル1の3成分を入力してください\n");
  read_vector3D(vector1);

  printf("ベクトル2の3成分を入力してください\n");
  read_vector3D(vector2);

  outer_product3D(vector1, vector2, vector3);
  printf("\n2つのベクトルに垂直なベクトル3（外積）は(%.2lf,%.2lf,%.2lf)です\n"
         , vector3[0], vector3[1], vector3[2]);

  inner_data = inner_product3D(vector1, vector3);
  printf("\n入力ベクトル1とベクトル3の内積は%.2lfです\n", inner_data);
  inner_data = inner_product3D(vector2, vector3);
  printf("入力ベクトル2とベクトル3の内積は%.2lfです\n", inner_data);
  return 0;
}


void read_vector3D(double vector[]){
  int i;
  for(i = 0; i < N; i++){
    scanf("%lf", &vector[i]);
  }
}


void outer_product3D(double vector1[], double vector2[], double vector3[]){
  vector3[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
  vector3[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
  vector3[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}


double inner_product3D(double vector1[], double vector2[]){
  double inner_data;

  inner_data = vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] *\
    vector2[2];

  return inner_data;
}
