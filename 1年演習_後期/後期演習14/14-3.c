#include <stdio.h>

void mark_board(int board[3][3], int turn);
void print_board(int board[3][3]); /* プロトタイプ宣言 */

int main(void) {
  int board[3][3] = {};            /* 0で初期化 */
  int i, turn = 1;

  for(i = 0; i < 9; i++){
    mark_board(board, turn);
    turn *= -1;
    print_board(board);
  }
  return 0;
}

void mark_board(int board[3][3], int turn){
  int H, W;

  if(turn == 1){
    printf("oのターンです\n");
    printf("縦位置は？");
    scanf("%d", &H);
    printf("横位置は？");
    scanf("%d", &W);
    board[H][W] = 1;
  } else {
    printf("xのターンです\n");
    printf("縦位置は？");
    scanf("%d", &H);
    printf("横位置は？");
    scanf("%d", &W);
    board[H][W] = -1;
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
