#include<stdio.h>
#include<string.h>

#define LENGTH 15

int main(void){
  int i = 0;
  int strl = 0; //文字数を入れる
  int str[LENGTH] = {}; //出現回数を入れる
  char word[100] = {};
  char *p_word; //word配列のアドレスを格納するポインタ
  int *p_str; //str配列のアドレスを格納するポインタ

  p_word = word;
  p_str = str;

  while(i < LENGTH){
    do{
      printf("%d番目の英単語を入力してください(15文字以内):\n", i+1);
      printf("--> ");
      scanf("%s", p_word);
      
      strl  = strlen(p_word);
	}while(strl >= LENGTH);

    if(strcmp(p_word, "*") == 0)
      break;

    *(p_str + strl) = *(p_str + strl) + 1;
    p_word++;
    i++;
  }

  printf("文字数    出現回数\n");
  for(i=0; i <= LENGTH-1; i++){
    printf(" %2d         %2d\n", i+1, *(p_str + i));
  }

  return 0;
}
