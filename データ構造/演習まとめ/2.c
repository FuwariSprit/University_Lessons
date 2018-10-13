#include<stdio.h>
#include<string.h>

#define NUM 25
#define WORD 15

typedef struct{
  char character;
  int count;
}initial;

void quick(initial chara[], int left, int right);
void swap(initial *a, initial *b);
void showlist(initial chara[]);

int main(void){
  char word[WORD];
  int i = 0;
  initial chara[NUM] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0},
			{'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
			{'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
			{'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
			{'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}};
  
  while(1){
    printf("英単語を入力してください：");
    scanf("%s", word);

    if(word[0] == 'z'){
      break;
    } else {
      for(i=0; i<NUM; i++){
	if(word[0] == chara[i].character){
	  chara[i].count++;
	}
      }
    }
  }

  quick(chara, 0, NUM-1);

  printf("出現回数順に出力します。\n");
  showlist(chara);

  return 0;
}

void quick(initial chara[], int left, int right){
  int pl = left;
  int pr = right;
  int pivot = (chara[pl].count + chara[pr].count) / 2;

  while(1){
    while(chara[pl].count > pivot) pl++;
    while(chara[pr].count < pivot) pr--;
    if(pr < pl) break;
    swap(&chara[pl], &chara[pr]);
    pl++;
    pr--;
  }

  if(left < pr)
    quick(chara, left, pr);
  if(pl < right)
    quick(chara, pl, right);
}

void swap(initial *a, initial *b){
  initial tmp = *a;
  *a = *b;
  *b = tmp;
}

void showlist(initial chara[]){
  int i;
  for(i=0; i<NUM; i++){
    if(chara[i].count > 0){
      printf("%c : %d回\n", chara[i].character, chara[i].count);
    }
  }
}
