#include<stdio.h>
int main(void) {
  int teihen, takasa, menseki ;
  
  printf("底辺を入れてください\n") ;
  scanf("%d", &teihen) ;
  printf("高さを入れてください\n") ;
  scanf("%d", &takasa) ;

  menseki = teihen * takasa / 2 ;

  printf("面積は%dです。\n", menseki) ;

  return 0 ;
}
