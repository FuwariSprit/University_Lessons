#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATANUM 54
#define FILENAME 50

unsigned char header[DATANUM];

void get_data(void);
//16進数変換 convert(header配列の添字4つ)
//4つ以下の場合はbmpの予約領域を割り当てること)
int convert(int a, int b, int c, int d);

int main(void){
  get_data();

  return 0;
}

void get_data(void){
  int c, i=0;
  int filesize, offset, width, height, bits;
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

  c = fgetc(fp);
  while(i <= DATANUM){
    header[i] = c;
    c = fgetc(fp);
    i++;
  }

  printf("＜ファイルタイプ＞\n");
  printf("header[0]=%02X header[1]=%02X\n\n", header[0], header[1]);

  printf("＜ファイルサイズ＞\n");
  printf("header[2]=%02X header[3]=%02X header[4]=%02X header[5]=%02X\n",
	 header[2], header[3], header[4], header[5]);
  filesize = convert(2, 3, 4, 5);
  printf("%dバイト\n\n", filesize);

  printf("＜予約領域＞\n");
  printf("header[6]=%02X header[7]=%02X header[8]=%02X header[9]=%02X\n\n",
	 header[6], header[7], header[8], header[9]);

  printf("＜オフセット＞\n");
  printf("header[10]=%02X header[11]=%02X header[12]=%02X header[13]=%02X\n",
	 header[10], header[11], header[12], header[13]);
  offset = convert(10, 11, 12, 13);
  printf("%dバイト\n\n", offset);

  printf("＜情報ヘッダサイズ＞\n");
  printf("header[14]=%02X header[15]=%02X header[16]=%02X header[17]=%02X\n\n",
	 header[14], header[15], header[16], header[17]);

  printf("＜画像の幅＞\n");
  printf("header[18]=%02X header[19]=%02X header[20]=%02X header[21]=%02X\n",
	 header[18], header[19], header[20], header[21]);
  width = convert(18, 19, 20, 21);
  printf("%d画素\n\n", width);

  printf("＜画像の高さ＞\n");
  printf("header[22]=%02X header[23]=%02X header[24]=%02X header[25]=%02X\n",
	 header[22], header[23], header[24], header[25]);
  height = convert(22, 23, 24, 25);
  printf("%dライン\n\n", height);

  printf("＜色プレーン数＞\n");
  printf("header[26]=%02X header[27]=%02X\n\n", header[26], header[27]);

  printf("＜1画素当たりのビット数＞\n");
  printf("header[28]=%02X header[29]=%02X\n", header[28], header[29]);
  bits = convert(28, 29, 6, 6);
  printf("%dビット\n\n", bits);

  printf("＜圧縮方式＞\n");
  printf("header[30]=%02X header[31]=%02X header[32]=%02X header[33]=%02X\n\n",
	 header[30], header[31], header[32], header[33]);

  printf("＜画像データサイズ＞\n");
  printf("header[34]=%02X header[35]=%02X header[36]=%02X header[37]=%02X\n\n",
	 header[34], header[35], header[36], header[37]);

  printf("＜水平解像度＞\n");
  printf("header[38]=%02X header[39]=%02X header[40]=%02X header[41]=%02X\n\n",
	 header[38], header[39], header[40], header[41]);

  printf("＜垂直解像度＞\n");
  printf("header[42]=%02X header[43]=%02X header[44]=%02X header[45]=%02X\n\n",
	 header[42], header[43], header[44], header[45]);

  printf("＜色数＞\n");
  printf("header[46]=%02X header[47]=%02X header[48]=%02X header[49]=%02X\n\n",
	 header[38], header[39], header[40], header[41]);

  printf("＜重要な色数＞\n");
  printf("header[50]=%02X header[51]=%02X header[52]=%02X header[53]=%02X\n\n",
	  header[50], header[51], header[52], header[53]);

  printf("＜挿入ビット数＞\n");
  printf("%dバイト\n\n", filesize-offset-width*height*(bits/8));

  fclose(fp);
  printf("ファイルをクローズしました.\n");
}

int convert(int a, int b, int c, int d){
  char cSum[100];
  sprintf(cSum, "%02X%02X%02X%02X",
	 header[d], header[c], header[b], header[a] );
  return (int)strtol(cSum, NULL, 16);
}
