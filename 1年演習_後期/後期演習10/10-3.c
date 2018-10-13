#include<stdio.h>
#include<string.h>

#define CHARA 50

int main(void){
  char first_name[CHARA], family_name[CHARA];
  int i, n;

  printf("名の字数を入力して下さい:");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    printf("first_name[%d]=", i);
    scanf("%*c%c", &first_name[i]);
  }
  first_name[n] = '\0';

  printf("姓の字数を入力して下さい:");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    printf("family_name[%d]=", i);
    scanf("%*c%c",&family_name[i]);
  }
  family_name[n] = '\0';

  printf("\n選手の氏名は\n");
  printf("姓:%s\n", family_name);
  printf("名:%s\n", first_name);

  return 0;
}
