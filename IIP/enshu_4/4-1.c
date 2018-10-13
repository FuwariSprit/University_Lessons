#include<stdio.h>

int main(void){
  double rgbYcbcr[3][3] = { {0.2990, 0.5870, 0.1140},
			     {-0.1687, -0.3313, 0.5000},
			     {0.5000, -0.4187, -0.0813} };
  double ycbcrRgb[3][3] = { {1.0000, 0.0000, 1.4020},
			    {1.0000, -0.3441, -0.7141},
			    {1.0000, 1.7720, 0.0000} };

  double rgb[3], ycbcr[3];

  printf("信号値を入力して下さい(実数値)\n");
  printf("R : ");
  scanf("%lf", &rgb[0]);
  printf("G : ");
  scanf("%lf", &rgb[1]);
  printf("B : ");
  scanf("%lf", &rgb[2]);

  printf("\n＜入力されたRGB信号(実数値)＞\n");
  printf("R:\t%.4lf\n", rgb[0]);
  printf("G:\t%.4lf\n", rgb[1]);
  printf("B:\t%.4lf\n", rgb[2]);

  ycbcr[0] = rgb[0]*rgbYcbcr[0][0] + rgb[1]*rgbYcbcr[0][1] + rgb[2]*rgbYcbcr[0][2];
  ycbcr[1] = rgb[0]*rgbYcbcr[1][0] + rgb[1]*rgbYcbcr[1][1] + rgb[2]*rgbYcbcr[1][2];
  ycbcr[2] = rgb[0]*rgbYcbcr[2][0] + rgb[1]*rgbYcbcr[2][1] + rgb[2]*rgbYcbcr[2][2];

  printf("\n＜変換されたYCbCr信号(実数値)＞\n");
  printf("Y:\t%.4lf\n", ycbcr[0]);
  printf("Cb:\t%.4lf\n", ycbcr[1]);
  printf("Cr:\t%.4lf\n", ycbcr[2]);

  rgb[0] = ycbcr[0]*ycbcrRgb[0][0] + ycbcr[1]*ycbcrRgb[0][1] + ycbcr[2]*ycbcrRgb[0][2];
  rgb[1] = ycbcr[0]*ycbcrRgb[1][0] + ycbcr[1]*ycbcrRgb[1][1] + ycbcr[2]*ycbcrRgb[1][2];
  rgb[2] = ycbcr[0]*ycbcrRgb[2][0] + ycbcr[1]*ycbcrRgb[2][1] + ycbcr[2]*ycbcrRgb[2][2];

  printf("\n＜再度変換されたRGB信号(実数値)＞\n");
  printf("R:\t%.4lf\n", rgb[0]);
  printf("G:\t%.4lf\n", rgb[1]);
  printf("B:\t%.4lf\n", rgb[2]);
  
  return 0;
}
