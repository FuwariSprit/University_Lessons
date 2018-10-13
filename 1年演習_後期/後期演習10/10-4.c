#include<stdio.h>
#include<string.h>

int get_length(char str[]);

#define CHARA 50

int main(void){
  int i, length = 0;
  char str[CHARA], rts[CHARA];

  printf("文字列:");
  scanf("%s", str);

  length = get_length(str);

  for(i = 0; i < length; i++){
    rts[length-i-1] = str[i];
  }
  rts[length] = '\0';

  printf("文字列の長さ:%d\n", length);
  printf("文字列（逆順）:%s.%s\n", str, rts);

  return 0;
}


int get_length(char str[]){
  int i, length = 0;
  for(i = 0; str[i] != '\0'; i++){
    length++;
  }

  return length;
}
