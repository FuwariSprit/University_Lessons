#include<stdio.h>
#include<string.h>

#define LENGTH 15

int main(void){
  int i = 0;
  int strl = 0; //文字数を入れる
  int str[LENGTH] = {}; //出現回数を入れる
  char word[100] = {};

  while(i < LENGTH){
    do{
      printf("%d番目の英単語を入力してください(15文字以内):\n", i+1);
      printf("--> ");
      scanf("%s", &word[i]);
      
      strl  = strlen(&word[i]);
	}while(strl >= LENGTH);

    if(strcmp(&word[i], "*") == 0)
      break;

    str[strl]++;
    i++;
  }

  printf("文字数    出現回数\n");
  for(i=0; i <= LENGTH-1; i++){
    printf(" %2d         %2d\n", i+1, str[i]);
  }

  return 0;
}
