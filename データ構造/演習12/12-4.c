#include<stdio.h>

#define STACK_SIZE 5
#define NO_DATA -1

int Push(int data);
int Pop();
void ShowStack();

int stack[STACK_SIZE];
int sp = -1;

int main(void){
  int i, state, data, jadge;

  for(i=0; i<STACK_SIZE; i++){
    stack[i] = NO_DATA;
  }

  while(1){
    printf("(1)Push (2)Pop (0)Exit :");
    scanf("%d", &state);

    if(state==1){
      printf("Data:");
      scanf("%d", &data);
      jadge = Push(data);
      if(jadge==-1){
	printf("Stack Overflow!\n");
	printf("Stack Push failed!\n");
      }

    } else if(state==2){
      jadge = Pop();
      if(jadge==-1){
	printf("Stack Empty!\n");
	printf("Stack Pop is failed!");
      } else {
	printf("Pop data is %d\n", jadge);      
      }

    } else if(state==0){
      break;
    }

    ShowStack();
  }

  return 0;
}

int Push(int data){
  sp++;

  if(sp==STACK_SIZE){
    sp--;
    return -1;
  } else {
    stack[sp] = data;
    return 0;
  }
}

int Pop(){
  if(sp<0){
    return -1;
  } else {
    int data = stack[sp];
    sp--;

    return data;
  }
}

void ShowStack(){
  int i;
  printf("Stack:");
  for(i=0; i<=sp; i++){
    printf("[%d]", stack[i]);
  }

  printf("\n");
}
