#include<stdio.h>

int main(void){
  int i;
  int data[3]={0};
  double rgb[3]={0};
  double newrgb[3]={};
  double ycbcr[3]={0};
  double newycbcr[3]={};
  double matrixY[3][3]={{0.2990,0.5870,0.1140},
		       {-0.1687,-0.3313,0.5000},
			{0.5000,-0.4187,-0.0813}};
  double matrixR[3][3]={{1.0000,0.0000,1.4020},
			{1.0000,-0.3441,-0.7141},
			{1.0000,1.7720,0.0000}};

  printf("信号値を入力して下さい(整数値)\n");
  printf("R : ");
  scanf("%d",&data[0]);
  printf("G : ");
  scanf("%d",&data[1]);
  printf("B : ");
  scanf("%d",&data[2]);

  printf("\n<入力されたRGB信号(実数値)>\n");
  printf("R : %d\n",data[0]);
  printf("G : %d\n",data[1]);
  printf("B : %d\n",data[2]);

  ycbcr[0]=matrixY[0][0]*(double)data[0]+matrixY[0][1]*(double)data[1]+matrixY[0][2]*(double)data[2];
  ycbcr[1]=matrixY[1][0]*(double)data[0]+matrixY[1][1]*(double)data[1]+matrixY[1][2]*(double)data[2];
  ycbcr[2]=matrixY[2][0]*(double)data[0]+matrixY[2][1]*(double)data[1]+matrixY[2][2]*(double)data[2];

  for(i=0;i<3;i++){
    if(ycbcr[i]>=0.0){
      newycbcr[i]=(int)(ycbcr[i]+0.5);
    }else{
      newycbcr[i]=(int)(ycbcr[i]-0.5);
    }
  }
  newycbcr[1]+=128;
  newycbcr[2]+=128;
  for(i=0;i<3;i++){
    if(newycbcr[i]<0){
      newycbcr[i]=0;
    }else if(newycbcr[i]>255){
      newycbcr[i]=255;
    }
  }

  rgb[0]=matrixR[0][0]*newycbcr[0]+matrixR[0][1]*(newycbcr[1]-128)+matrixR[0][2]*(newycbcr[2]-128);
  rgb[1]=matrixR[1][0]*newycbcr[0]+matrixR[1][1]*(newycbcr[1]-128)+matrixR[1][2]*(newycbcr[2]-128);
  rgb[2]=matrixR[2][0]*newycbcr[0]+matrixR[2][1]*(newycbcr[1]-128)+matrixR[2][2]*(newycbcr[2]-128);

  for(i=0;i<3;i++){
    if(rgb[i]>=0.0){
      newrgb[i]=rgb[i]+0.5;
    }else{
      newrgb[i]=rgb[i]-0.5;
    }
  }

  printf("\n<変換されたYCbCr信号(実数値)>\n");
  printf("R : %3.4f\n",ycbcr[0]);
  printf("G : %3.4f\n",ycbcr[1]);
  printf("B : %3.4f\n",ycbcr[2]);

  printf("\n<変換されたYCbCr信号(整数値)>\n");
  printf("R : %3d\n",(int)newycbcr[0]);
  printf("G : %3d\n",(int)newycbcr[1]);
  printf("B : %3d\n",(int)newycbcr[2]);

  printf("\n<再度変換されたRGB信号(実数値)>\n");
  printf("R : %3.4f\n",rgb[0]);
  printf("G : %3.4f\n",rgb[1]);
  printf("B : %3.4f\n",rgb[2]);

  printf("\n<再度変換されたRGB信号(整数値)>\n");
  printf("R : %3d\n",(int)newrgb[0]);
  printf("G : %3d\n",(int)newrgb[1]);
  printf("B : %3d\n",(int)newrgb[2]);

  return 0;
}
