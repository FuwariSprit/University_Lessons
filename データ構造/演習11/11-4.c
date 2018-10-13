#include<stdio.h>
#include<stdlib.h>
#define num 20

int head=0;

struct MyList{
  int IntData;
  int NextIndex;
};
void ShowList(struct MyList data[]);

int main(void){
  struct MyList data[num]={{1,3},{9,2},{4,5},{3,4},{5,1},
			   {15,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},
			   {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
  ShowList(data);
  return 0;
}

void ShowList(struct MyList data[]){
  int i;
  printf("リスト：");
  i=head;
  while(1){
    printf("%d ",data[i].IntData);
    i=data[i].NextIndex;
    if(i==-1){
      printf("\n");
      exit(0);
    }
  }
}
