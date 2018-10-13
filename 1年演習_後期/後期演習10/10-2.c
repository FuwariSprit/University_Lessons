#include<stdio.h>
#include<string.h>

#define CHARA 50

int main(void) {
  char first_name[] = "Daisuke";
  char family_name[CHARA];

  printf("姓を入力して下さい:");
  scanf("%s", family_name);


  printf("< 2つの文字列を表示します >\n");
  printf("姓:%s\n", family_name);
  printf("名:");
  for(int i = 0; first_name[i] != '\0'; i++){
    printf("%c", first_name[i]);
  }
  printf("\n");

  return 0;
}
