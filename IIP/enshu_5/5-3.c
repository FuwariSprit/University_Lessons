#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATANUM 54
#define IMAGEDATA 512
#define FILENAME 50

unsigned char header[DATANUM];
unsigned char imgin[3][IMAGEDATA][IMAGEDATA];
unsigned char imgout[3][IMAGEDATA][IMAGEDATA];

double rgbYcbcr[3][3] = { {0.2990, 0.5870, 0.1140},
			  {-0.1687, -0.3313, 0.5000},
			  {0.5000, -0.4187, -0.0813} };

double ycbcrRgb[3][3] = { {1.0000, 0.0000, 1.4020},
			  {1.0000, -0.3441, -0.7141},
			  {1.0000, 1.7720, 0.0000} };

int filesize, offset, width, height, bits;

void get_data(void);
void put_data(void);
void processing(void);

//16進数変換 convert(header配列の添字4つ)
//4つ以下の場合はbmpの予約領域を割り当てること)
int convert(int a, int b, int c, int d);

void rgb_to_ybr(void);
void ybr_to_rgb(void);

int main(void){
  get_data();
  rgb_to_ybr();
  processing();
  ybr_to_rgb();
  put_data();

  return 0;
}

void processing(void){
  int i,j;

  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      if((i<height/2 && j<width/2) || (i>height/2 && j>width/2)){
	imgout[0][j][i] = 16;
	imgout[1][j][i] = 128;
	imgout[2][j][i] = 128;
      } else {
	imgout[0][j][i] = imgin[0][j][i];
	imgout[1][j][i] = imgin[1][j][i];
	imgout[2][j][i] = imgin[2][j][i];      
      }
    }
  }

  printf("\n出力画像データを作成しました.\n");
}

void get_data(void){
  int c, i, j;
  char fileName[FILENAME];
  FILE *fp;

  printf("入力ファイル名を入力して下さい:");
  scanf("%s", fileName);

  fp = fopen(fileName, "rb");
  if(fp == NULL){
    printf("ファイルをオープンできませんでした.\n");
    exit (1);
  }
  printf("ファイルをオープンしました.\n");

  //ヘッダー取得

  for(i=0; i < DATANUM; i++){
    c = fgetc(fp);
    header[i] = c;
  }

  printf("＜ファイルサイズ＞\n");
  filesize = convert(2, 3, 4, 5);
  printf("%dバイト\n\n", filesize);

  printf("＜オフセット＞\n");
  offset = convert(10, 11, 12, 13);
  printf("%dバイト\n\n", offset);

  printf("＜画像の幅＞\n");
  width = convert(18, 19, 20, 21);
  printf("%d画素\n\n", width);

  printf("＜画像の高さ＞\n");
  height = convert(22, 23, 24, 25);
  printf("%dライン\n\n", height);

  printf("＜1画素当たりのビット数＞\n");
  bits = convert(28, 29, 6, 6);
  printf("%dビット\n\n", bits);

  printf("＜挿入ビット数＞\n");
  printf("%dバイト\n\n", filesize-offset-width*height*(bits/8));

  //画像データ取得
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      imgin[2][j][i] = fgetc(fp);
      imgin[1][j][i] = fgetc(fp);
      imgin[0][j][i] = fgetc(fp);
    }
  }

  fclose(fp);
  printf("ファイルをクローズしました.\n");
}
 
void put_data(void){
  int i, j;
  char fileName[FILENAME];
  FILE *fp;
  
  printf("出力ファイル名を入力して下さい:");
  scanf("%s", fileName);

  fp = fopen(fileName, "wb");
  if(fp == NULL){
    printf("ファイルをオープンできませんでした.\n");
    exit (1);
  }
  printf("ファイルをオープンしました.\n");

  for(i=0; i<DATANUM; i++){
    fputc(header[i], fp);
  }
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      fputc(imgout[2][j][i], fp);
      fputc(imgout[1][j][i], fp);
      fputc(imgout[0][j][i], fp);
    }
  }  
  
  fclose(fp);
  printf("ファイルをクローズしました.\n");
}

int convert(int a, int b, int c, int d){
  char cSum[100];
  sprintf(cSum, "%02X%02X%02X%02X",
	 header[d], header[c], header[b], header[a] );
  return (int)strtol(cSum, NULL, 16);
}


void rgb_to_ybr(void){
  int i, j, k;
  double data;
  double ycbcr[3];

  //----- RGB→YCbCrの色空間変換 -----
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      ycbcr[0] = imgin[0][j][i]*rgbYcbcr[0][0] + imgin[1][j][i]*rgbYcbcr[0][1] + imgin[2][j][i]*rgbYcbcr[0][2];
      ycbcr[1] = imgin[0][j][i]*rgbYcbcr[1][0] + imgin[1][j][i]*rgbYcbcr[1][1] + imgin[2][j][i]*rgbYcbcr[1][2];
      ycbcr[2] = imgin[0][j][i]*rgbYcbcr[2][0] + imgin[1][j][i]*rgbYcbcr[2][1] + imgin[2][j][i]*rgbYcbcr[2][2];

      for(k=0; k<3; k++){
	data = 0.1 * ycbcr[k];
	if(data >= 0.0){
	  ycbcr[k] = (int)(ycbcr[k]+0.5);
	} else {
	  ycbcr[k] = (int)(ycbcr[k]-0.5);
	}
      }

      for(k=1; k<3; k++){
	ycbcr[k] += 128;
      }

      for(k=0; k<3; k++){
	if(ycbcr[k] > 255){
	  ycbcr[k] = 255;
	} else if(ycbcr[k] < 0) {
	  ycbcr[k] = 0;
	}
      }
      
      imgin[0][j][i] = (int)ycbcr[0];
      imgin[1][j][i] = (int)ycbcr[1];
      imgin[2][j][i] = (int)ycbcr[2];
    }
  }
}

void ybr_to_rgb(void){
  int i, j, k;
  double data;
  double rgb[3];

  //----- YCbCr→RGBの色空間変換 -----
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      rgb[0] = imgout[0][j][i]*ycbcrRgb[0][0] + (imgout[1][j][i]-128)*ycbcrRgb[0][1] + (imgout[2][j][i]-128)*ycbcrRgb[0][2];
      rgb[1] = imgout[0][j][i]*ycbcrRgb[1][0] + (imgout[1][j][i]-128)*ycbcrRgb[1][1] + (imgout[2][j][i]-128)*ycbcrRgb[1][2];
      rgb[2] = imgout[0][j][i]*ycbcrRgb[2][0] + (imgout[1][j][i]-128)*ycbcrRgb[2][1] + (imgout[2][j][i]-128)*ycbcrRgb[2][2];

      for(k=0; k<3; k++){
	data = 0.1 * rgb[k];
	if(data >= 0.0){
	  rgb[k] = (int)(rgb[k]+0.5);
	} else {
	  rgb[k] = (int)(rgb[k]-0.5);
	}
      }
 
      for(k=0; k<3; k++){
	if(rgb[k] > 255){
	  rgb[k] = 255;
	} else if(rgb[k] < 0) {
	  rgb[k] = 0;
	}
      }
      
      imgout[0][j][i] = (int)rgb[0];
      imgout[1][j][i] = (int)rgb[1];
      imgout[2][j][i] = (int)rgb[2];
    }
  }
}
