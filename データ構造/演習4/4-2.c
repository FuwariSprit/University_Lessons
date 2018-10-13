#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i;
  char name[] = "Nihon University";
  char *p;
  char *str;
  int num = 0; //スペース記号の位置を格納
  
  //スペース記号の位置を調べる
  p = name;
  while(*p != '\0'){
    num++;
    if(*p == ' '){
      printf("%d文字目に見つかりました!\n", num);
      break;
    }
    p++;
  }

  //スペース記号の左側を保存する領域を確保
  str = (char*)malloc(11*sizeof(char));

  //スペース記号左側の文字列をmallocで確保した領域にコピー
  for(i=0; i<num; i++){
    *(str+i) = name[i];
  }
  *(str+i) = '\0';

  //スペース記号の左側の文字列を画面に表示
  printf("%s\n", str);

  //mallocで確保した領域の確保
  free(str);
  
  return 0;
}
