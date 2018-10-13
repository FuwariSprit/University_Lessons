#include<stdio.h>

int main(void){
  int i;
  double rgbYcbcr[3][3] = { {0.2990, 0.5870, 0.1140},
			     {-0.1687, -0.3313, 0.5000},
			     {0.5000, -0.4187, -0.0813} };
  double ycbcrRgb[3][3] = { {1.0000, 0.0000, 1.4020},
			    {1.0000, -0.3441, -0.7141},
			    {1.0000, 1.7720, 0.0000} };

  int rgbInt[3], ycbcrInt[3];
  double rgb[3], ycbcr[3];
  double data;                //四捨五入用

  printf("信号値を入力して下さい(整数値)\n");
  printf("R : ");
  scanf("%d", &rgbInt[0]);
  printf("G : ");
  scanf("%d", &rgbInt[1]);
  printf("B : ");
  scanf("%d", &rgbInt[2]);

  printf("\n＜入力されたRGB信号(整数値)＞\n");
  printf("R:\t%d\n", rgbInt[0]);
  printf("G:\t%d\n", rgbInt[1]);
  printf("B:\t%d\n", rgbInt[2]);

  ycbcr[0] = rgbInt[0]*rgbYcbcr[0][0] + rgbInt[1]*rgbYcbcr[0][1] + rgbInt[2]*rgbYcbcr[0][2];
  ycbcr[1] = rgbInt[0]*rgbYcbcr[1][0] + rgbInt[1]*rgbYcbcr[1][1] + rgbInt[2]*rgbYcbcr[1][2];
  ycbcr[2] = rgbInt[0]*rgbYcbcr[2][0] + rgbInt[1]*rgbYcbcr[2][1] + rgbInt[2]*rgbYcbcr[2][2];

  printf("\n＜変換されたYCbCr信号(実数値)＞\n");
  printf("Y:\t%.4lf\n", ycbcr[0]);
  printf("Cb:\t%.4lf\n", ycbcr[1]);
  printf("Cr:\t%.4lf\n", ycbcr[2]);

  
  for(i=0; i<3; i++){
    data = 0.1 * ycbcr[i];
    if(data >= 0.0)
      ycbcrInt[i] = (int)(ycbcr[i]+0.5);
    else
      ycbcrInt[i] = (int)(ycbcr[i]-0.5);
  }
  
  ycbcrInt[1] += 128;
  ycbcrInt[2] += 128;
 
  for(i=0; i<3; i++){
    if(ycbcrInt[i] > 255){
      ycbcrInt[i] = 255;
    } else if(ycbcrInt[i] < 0){
      ycbcrInt[i] = 0;
    }
  }

  printf("\n＜変換されたYCbCr信号(整数値)＞\n");
  printf("Y:\t%d\n", ycbcrInt[0]);
  printf("Cb:\t%d\n", ycbcrInt[1]);
  printf("Cr:\t%d\n", ycbcrInt[2]);

  for(i=1; i<3; i++){
    ycbcrInt[i] -= 128;
  }

  rgb[0] = ycbcrInt[0]*ycbcrRgb[0][0] + ycbcrInt[1]*ycbcrRgb[0][1] + ycbcrInt[2]*ycbcrRgb[0][2];
  rgb[1] = ycbcrInt[0]*ycbcrRgb[1][0] + ycbcrInt[1]*ycbcrRgb[1][1] + ycbcrInt[2]*ycbcrRgb[1][2];
  rgb[2] = ycbcrInt[0]*ycbcrRgb[2][0] + ycbcrInt[1]*ycbcrRgb[2][1] + ycbcrInt[2]*ycbcrRgb[2][2];

  printf("\n＜再度変換されたRGB信号(実数値)＞\n");
  printf("R:\t%.4lf\n", rgb[0]);
  printf("G:\t%.4lf\n", rgb[1]);
  printf("B:\t%.4lf\n", rgb[2]);
  
  for(i=0; i<3; i++){
    data = 0.1 * rgb[i];
    if(data >= 0.0)
      rgbInt[i] = (int)(rgb[i]+0.5);
    else
      rgbInt[i] = (int)(rgb[i]-0.5);
  }


  for(i=0; i<3; i++){
    if(rgbInt[i] > 255){
      rgbInt[i] = 255;
    } else if(rgbInt[i] < 0){
      rgbInt[i] = 0;
    }
  }
  
  printf("\n＜再度変換されたRGB信号(整数値)＞\n");
  printf("R:\t%d\n", rgbInt[0]);
  printf("G:\t%d\n", rgbInt[1]);
  printf("B:\t%d\n", rgbInt[2]);
  
  return 0;
}
