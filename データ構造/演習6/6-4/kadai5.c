#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#define MAX_SIZE 256

int main(void){
  FILE *fp_in, *fp_out;
  int x, y;
  int width, height;
  char r[MAX_SIZE][MAX_SIZE];
  char g[MAX_SIZE][MAX_SIZE];
  char b[MAX_SIZE][MAX_SIZE];

  fp_in = fopen("N.bmp", "rb");

  readBMPHeader(fp_in, &height, &width);

  for(y=0; y<height; y++){
    for(x=width-1; x>=0; x--){
      fread(&b[x][y], sizeof(b[y][x]), 1, fp_in);
      fread(&g[x][y], sizeof(g[y][x]), 1, fp_in);
      fread(&r[x][y], sizeof(r[y][x]), 1, fp_in);
    }
  }
  
  //画像データの加工(黒い部分を赤くする)
  for(y=0; y<height; y++){
    for(x=0; x<width; x++){
      if(b[x][y]==0 && g[x][y]==0 && r[x][y]==0){
	b[x][y] = 0;
	g[x][y] = 0;
	r[x][y] = 255;
      }
    }
  }
  
  fp_out = fopen("redMirror.bmp", "wb");

  writeBMPHeader(fp_out, height, width);

  //画像データの書き込み
  for(y=0; y<height; y++){
    for(x=0; x<width; x++){
      fwrite(&b[x][y], sizeof(b[y][x]), 1, fp_out);
      fwrite(&g[x][y], sizeof(g[y][x]), 1, fp_out);
      fwrite(&r[x][y], sizeof(r[y][x]), 1, fp_out);
    }
  }

  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
