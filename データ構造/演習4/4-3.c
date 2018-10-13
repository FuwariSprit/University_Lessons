#include<stdio.h>
#include<stdlib.h>

int find(char *s, char c);

int main(void){
  int i;
  char name[] = "Nihon University";
  //  char *p;
  char *str; //スペースの左側を保存する領域
  int num = 0; //スペース記号の位置を格納

  num = find(name, ' '); //スペースの位置を調べる
  
  /*
  p = name;
  while(*p != '\0'){
    num++;
    if(*p == ' '){
      printf("%d文字目に見つかりました!\n", num);
      break;
    }
    p++;
    } */

  if(num == -1){
    printf("スペース記号は見つかりませんでした\n");
    return 0;
  }
  else {
    
    //スペース記号の左側を保存する領域を確保
    str = (char*)malloc(6*sizeof(char));
    
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
}


int find(char *s, char c){
  int num = 0;

  while(*s != '\0'){
    num++;
    if(*s == c){
      printf("%d文字目に見つかりました！\n", num);
      return num;
    }
    s++;
  }

  return -1;
}
