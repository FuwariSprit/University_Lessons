#include<stdio.h>
void fstrcpy(char *p1, char *p2); //文字列のコピー
void fstrcat(char *p1, char *p2); //文字列の連結

int main(void){
  char moji1[10], moji2[10];

  fstrcpy(moji1, "ABC"); //moji1に"ABC"を格納
  fstrcpy(moji2, "DEF"); //moji2に"DEF"を格納
  fstrcat(moji1, moji2); //moji1の後ろにmoji2を連結
  
  printf("moji1: %s\n", moji1); //moji1を表示
  printf("moji2: %s\n", moji2); //moji2を表示

  return 0;
}

//文字列のコピー,文字列p2をp1にコピー
void fstrcpy(char *p1, char *p2){
  //p1にp2を1文字ずつコピー
  while(*p2 != '\0'){
    *p1 = *p2;
    p1++;
    p2++;
  }
  *p1 = '\0';
}

//文字列の連結,文字列p2を文字列p2を文字列p1の後ろに連結
void fstrcat(char *p1, char *p2){
  //p1のまつびまで(ヌル文字が現れるまで)ポインタの指す位置を動かす
  while(*p1 != '\0'){
    p1++;
  }
  
  //p1の末尾にp2を1文字ずつコピーして,の末尾にヌル文字を代入
  while(*p2 != '\0'){
    *p1 = *p2;
    p1++;
    p2++;
  }
  *p1 = '\0';
}
