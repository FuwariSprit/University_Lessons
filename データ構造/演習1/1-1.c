#include<stdio.h>
#define NUM 15     //盤面の数
void print_board(int board[NUM][NUM]);
void mark_board(int board[NUM][NUM],int turn);
int judge(int board[NUM][NUM]);

int main(void){
  int board[NUM][NUM] = {};
  int turn = 1,win_lose;
  
  while(1){
    mark_board(board,turn);
    print_board(board);
    win_lose=judge(board);
    if(win_lose==1 || win_lose==-1 || win_lose==-2){
      break;
    }
    turn *= -1;
  }
  if(win_lose==1){
    printf("先手の勝ちです\n");
  }else if(win_lose==-1){
    printf("後手の勝ちです\n");
  }else{
    printf("引き分けです\n");
  }

  return 0;
}

void print_board(int board[NUM][NUM]){
  int i, j;
  printf(" ");
  for(i=0; i<NUM; i++){     //横の番地の表示
    printf("%d", i%10);     //十の位になったら0からスタート
  }
  printf("\n");     //縦の番地の表示
  for(i=0; i<NUM; i++){
    printf("%d", i%10);
    for(j=0; j<NUM; j++){
      if(board[i][j]==0){
	printf(" ");
      }else if(board[i][j]==1){
	printf("o");
      }else{
	printf("x");
      }
    }
    printf("\n");
  }
}

void mark_board(int board[NUM][NUM],int turn){
  int height, width;
  if(turn==1){
    printf("先手の番です\n");
  }else{
    printf("後手の番です\n");
  }
  while(1){
    printf("縦位置は？");
    scanf("%d", &height);
    printf("横位置は？");
    scanf("%d", &width);
    if(board[height][width]==0 && height>=0 && width>=0 && height<NUM && width<NUM){
      break;
    }
    printf("そこには置けません\n");
  }
  if(turn==1){
    board[height][width] = 1;
  }else{
    board[height][width] = -1;
  }
}

int judge(int board[NUM][NUM]){
  int i, j, ans = 0;
  static int count = 0;

  for(i=0; i<NUM; i++){
    for(j=0; j<11; j++){
      if(board[i][j]==1){
	if(board[i][j+1]==1 && board[i][j+2]==1 && board[i][j+3]==1 && board[i][j+4]==1){
	  ans = 1;
	}
      }else if(board[i][j]==-1){
	if(board[i][j+1]==-1 && board[i][j+2]==-1 && board[i][j+3]==-1 && board[i][j+4]==-1){
	  ans = -1;
	}
      }
    }
  }

  for(i=0; i<11; i++){
    for(j=0; j<NUM; j++){
      if(board[i][j]==1){
	if(board[i+1][j]==1 && board[i+2][j]==1 && board[i+3][j]==1 && board[i+4][j]==1){
	  ans = 1;
	}
      }else if(board[i][j]==-1){
	if(board[i+1][j]==-1 && board[i+2][j]==-1 && board[i+3][j]==-1 && board[i+4][j]==-1){
	  ans = -1;
	}
      }
    }
  }

  for(i=0; i<11; i++){
    for(j=0; j<NUM; j++){
      if(board[i][j]==1){
	if(board[i+1][j+1]==1 && board[i+2][j+2]==1 && board[i+3][j+3]==1 && board[i+4][j+4]==1){
	  ans = 1;
	}
      }else if(board[i][j]==-1){
	if(board[i+1][j+1]==-1 && board[i+2][j+2]==-1 && board[i+3][j+3]==-1 && board[i+4][j+4]==-1){
	  ans=-1;
	}
      }
    }
  }

  for(i=4;i<NUM;i++){
    for(j=0;j<11;j++){
      if(board[i][j]==1){
	if(board[i-1][j+1]==1 && board[i-2][j+2]==1 && board[i-3][j+3]==1 && board[i-4][j+4]==1){
	  ans = 1;
	}
      }else if(board[i][j]==-1){
	if(board[i-1][j+1]==-1 && board[i-2][j+2]==-1 && board[i-3][j+3]==-1 && board[i-4][j+4]==-1){
	  ans = -1;
	}
      }
    }
  }

  count++;
  if(count==225){
    ans = -2;
  }

  return ans;
}
