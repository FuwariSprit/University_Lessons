#include <stdio.h>

void mark_board(int board[3][3], int turn);
void print_board(int board[3][3]); /* プロトタイプ宣言 */
int judge(int board[3][3]);

int main(void) {
  int board[3][3] = {};            /* 0で初期化 */
  int i, turn = 1, result;
  
  for(i = 0; i < 9; i++){
    mark_board(board, turn);
    turn = turn * -1;
    print_board(board);
    result = judge(board);
    switch(result){
    case 1:
      printf("oの勝ちです\n");
      return 0;
    case -1:
      printf("xの勝ちです\n");
      return 0;
    case -2:
      printf("引き分けです\n");
    case 0:
      break;
    }
  }

  return 0;
}

void mark_board(int board[3][3], int turn){
  int H, W;
  
  if(turn == 1){
    printf("oのターンです\n");
    do{
      printf("縦位置は？");
      scanf("%d", &H);
      printf("横位置は？");
      scanf("%d", &W);
      if(board[H][W] != 0 || H >= 3 || H < 0 || W >= 3 || W < 0){
	printf("そこには置けません\n");
      } else {	
	board[H][W] = 1;
      }
    }while(board[H][W] <= 0 || H >= 3 || H < 0 || W >= 3 || W < 0);
  }
  
  else {
    printf("xのターンです\n");
    do{
      printf("縦位置は？");
      scanf("%d", &H);
      printf("横位置は？");
      scanf("%d", &W);
      if(board[H][W] != 0 || H >= 3 || H < 0 || W >= 3 || W < 0){
	printf("そこには置けません\n");
      } else {
	board[H][W] = -1;
      }
    }while(board[H][W] >= 0 || H >= 3 || H < 0 || W >= 3 || W < 0);
    
  }
}

void print_board(int board[3][3]){
  int i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      printf("|");
      switch (board[i][j]){
      case 1 :
	printf("o");
	break;
      case -1 :
	printf("x");
	break;
      default :
	printf(" ");
	break;
      }
    }
    printf("|\n");
  }
}

int judge(int board[3][3]){
  int i, j, result_sum = 0;
  
  for(i = 0; i < 3; i++){     //横の判定
    result_sum = 0;
    for(j = 0; j < 3; j++){
      result_sum += board[i][j];
      if(result_sum == 3){
	return 1;
      }
      if(result_sum == -3){
	return -1;
      }
    }
  }
  
  for(j = 0; j < 3; j++){     //縦の判定
    result_sum = 0;
    for(i = 0; i < 3; i++){
      result_sum += board[i][j];
      if(result_sum == 3){
	return 1;
      }
      if(result_sum == -3){
	return -1;
      }
    }
  }
  
  result_sum = 0;     //斜めの判定
  result_sum = board[0][0] + board[1][1] + board[2][2];
  if(result_sum == 3){
    return 1;
  }
  if(result_sum == -3){
    return -1;
  }
  result_sum = 0;
  result_sum = board[0][2] + board[1][1] + board[2][0];
  if(result_sum == 3){
    return 1;
  }
  if(result_sum == -3){
    return -1;
  }
  
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(board[i][j] == 0){
	return 0;
      }
    }
  }

  return -2;
}
