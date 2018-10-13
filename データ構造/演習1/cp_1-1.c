#include <stdio.h>
#define BOARD_N 15 /* 盤面の合計数  */

void mark_board(int board[BOARD_N][BOARD_N], int point[2], int turn);
void print_board(int board[BOARD_N][BOARD_N]); /* プロトタイプ宣言 */
int judge(int board[BOARD_N][BOARD_N], int point[2], int turn);

int main(void) {
  int board[BOARD_N][BOARD_N] = {};            /* 0で初期化 */
  int point[2];
  int i, turn = 1, result;
  
  for(i = 0; i < BOARD_N * BOARD_N; i++){
    mark_board(board, point, turn);
    turn = turn * -1;
    print_board(board);
    result = judge(board, point, turn);
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

void mark_board(int board[BOARD_N][BOARD_N], int point[2], int turn){
  int H, W;
  
  if(turn == 1){
    printf("oのターンです\n");
    do{
      printf("縦位置は？");
      scanf("%d", &H);
      printf("横位置は？");
      scanf("%d", &W);
      if(board[H][W] != 0 || H >= BOARD_N || H < 0 || W >= BOARD_N || W < 0){
	printf("そこには置けません\n");
      } else {	
	board[H][W] = 1;
      }
    }while(board[H][W] <= 0 || H >= BOARD_N || H < 0 || W >= BOARD_N || W < 0);
  }
  
  else {
    printf("xのターンです\n");
    do{
      printf("縦位置は？");
      scanf("%d", &H);
      printf("横位置は？");
      scanf("%d", &W);
      if(board[H][W] != 0 || H >= BOARD_N || H < 0 || W >= BOARD_N || W < 0){
	printf("そこには置けません\n");
      } else {
	board[H][W] = -1;
      }
    }while(board[H][W] >= 0 || H >= BOARD_N || H < 0 || W >= BOARD_N || W < 0);
    
  }

  point[0] = H;
  point[1] = W;

}

void print_board(int board[BOARD_N][BOARD_N]){
  int i, j;
  for(i = 0; i < BOARD_N; i++){
    for(j = 0; j < BOARD_N; j++){
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

int judge(int board[BOARD_N][BOARD_N], int point[2], int turn){
  int i, j, count = -4;
  //横の判定　右
  while(i = point[1] < BOARD_N){
    if(board[point[0]][i] == turn){
      count++;
    } else {
      break;
    }
    i++;
  }
  //横の判定　左
  while(i = point[1] < BOARD_N){
    if(board[point[0]][i] == turn){
      count++;
    } else {
      break;
  }
    i--;
  }
  //縦の判定　上
  while(i = point[0] < BOARD_N){
    if(board[i][point[1]] == turn){
      count++;
    } else {
      break;
  }
    i--;
  } 
  //縦の判定　下
  while(i = point[0] < BOARD_N){
    if(board[i][point[1]] == turn){
      count++;
    } else {
      break;
  }
    i++;
  } 

  //勝敗判定
  if(count >= 5){
    switch(turn){
    case 1:
      return 1;
    case -1:
      return -1;
    default:
      break;
    }
  }
}

 
