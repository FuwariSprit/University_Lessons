#include<stdio.h>
int main(void) {
  int h, w, x = 0, y = 0 ;

  while(1) {
    printf("H:") ;
    scanf("%d", &h) ;
    printf("W:") ;
    scanf("%d", &w) ;
    
    if(h == 0 || w == 0) {
      break ;
    }
    for(x = 1 ; x <= h ; x++) {
      if(x > 1 && x < h) {
	printf("#") ;
	for(y = 1 ; y <= w-2 ; y++) {
	  printf(".") ;
	}
	printf("#\n") ;
      } else {
	for(y = 1 ; y <= w ; y++) {
	  printf("#") ;
	}
	printf("\n") ;
      }
    }
    printf("\n") ;
  }
  
  return 0 ;
}
