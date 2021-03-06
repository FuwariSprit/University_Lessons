#include<stdio.h>

#define NUM 11

void ShowList(int data[]);
int InsertNode(int no, int insdata, int data[]);
int DeleteNode(int no, int data[]);

int main(void){
  int i, no, insdata;
  int index[NUM] = {2, 4, 6, 8, 10, 12, 14, 16, 18, -1, -1};

  ShowList(index);
 
  while(1){
    printf("編集選択(挿入=0, 削除=1, 編集終了=-1):");
    scanf("%d", &i);
    
    if(i == 0){
      printf("挿入位置:");
      scanf("%d", &no);
      printf("挿入データ:");
      scanf("%d", &insdata);
      i = InsertNode(no-1, insdata, index);
      if(i == -1){
	printf("挿入失敗しました\n");
      }
    } 
    else if(i == 1){
      printf("削除位置:");
      scanf("%d", &no);
      i = DeleteNode(no-1, index);
      if(i == -1){
	printf("削除失敗しました\n");
      }
    }
    else if(i == -1){
      break;
    }
    
    ShowList(index);
  }

  return 0;
}

void ShowList(int data[]){
  printf("リスト:");
  for(int i=0; i<NUM; i++){
    if(data[i]==-1){
      break;
    }
    printf("%d ", data[i]);
  }
  printf("\n");
}

int InsertNode(int no, int insdata, int data[]){
  int i;

  for(i=0; data[i]!=-1; i++){
    if(i>=NUM-1){
      return -1;
    }
  } 

  for(i=NUM; i>no; i--){
    data[i] = data[i-1];
  }

  data[no] = insdata;

  return 0;
}

int DeleteNode(int no, int data[]){
  int i;

  if(data[no] == -1){
    return -1;
  }
  
  for(i=no; i<NUM; i++){
    data[i] = data[i+1];
  }

  return 0;
}
