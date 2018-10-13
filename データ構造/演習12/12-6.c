#include<stdio.h>

#define STACK_SIZE 5
#define QUEUE_SIZE 5
#define NO_DATA -1

/*-----Stack-----*/
int Push(int data);
int Pop();
void ShowStack();
/*---------------*/

/*-----Queue-----*/
int EnQueue(int data);
int DeQueue();
void ShowQueue();
/*---------------*/

/*-----Stack-----*/
int stack[STACK_SIZE];
int sp = -1;
/*---------------*/

/*-----Queue-----*/
int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;
int num = 0;
/*---------------*/

int main(void){
  int i, state, data, jadge;

  for(i=0; i<STACK_SIZE; i++){
    stack[i] = NO_DATA;
  }
  for(i=0; i<QUEUE_SIZE; i++){
    queue[i] = NO_DATA;
  }
  
  while(1){
    printf("(1)Push (2)Pop (3)Enq (4)Deq (5)Push(Deq) (6)Enq(Pop) (0)Exit :");
    scanf("%d", &state);
    
    if(state==1){
      printf("Data:");
      scanf("%d", &data);
      jadge = Push(data);
      if(jadge==-1){
        printf("Stack Overflow!\n");
        printf("Stack Push failed!\n");
      } else {
	ShowStack();
      }
      
    } else if(state==2){
      jadge = Pop();
      if(jadge==-1){
        printf("Stack Empty!\n");
        printf("Stack Pop is failed!\n");
      } else {
        printf("Pop data is %d\n", jadge);
      }
      
    } else if(state==3){
      printf("Data:");
      scanf("%d", &data);
      jadge = EnQueue(data);
      if(jadge==-1){
	printf("Queue is full!\n");
	printf("Enqueue is failed!\n");
      } else {
	ShowQueue();
      }
      
    } else if(state==4){
      jadge = DeQueue();
      if(jadge==-1){
	printf("Queue is Empty!\n");
	printf("Dequeue is failed!\n");
      } else {
	printf("Dequeue data is %d\n", jadge);
      }
      
    } else if(state==5){
      jadge = DeQueue();
      if(jadge==-1){
	printf("Queue is Empty!\n");
        printf("Dequeue is failed!\n");
      } else {
	printf("Dequeue data is %d\n", jadge);
      }
      if(jadge>=0){
	jadge = Push(jadge);
	ShowStack();
	ShowQueue();
      }
      
    } else if(state==6){
      jadge = Pop();
      if(jadge==-1){
	printf("Stack is Empty!\n");
	printf("Pop is failed!\n");
      } else {
	printf("Pop data is %d\n", jadge);
      }
      if(jadge>=0){
	jadge = EnQueue(jadge);
	ShowStack();
	ShowQueue();
      }
      
    } else if(state==0){
      break;
    }
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

int EnQueue(int data){
  if(num==QUEUE_SIZE){
    return -1;
  } else {
    queue[rear] = data;
    rear++;
    num++;
    
    if(rear==QUEUE_SIZE){
      rear = 0;
    }
    
    return 0;
  }
}

int DeQueue(){
  if(num==0){
    return -1;
  } else {
    int data = queue[front];
    queue[front] = NO_DATA;
    front++;
    num--;
    
    if(front==QUEUE_SIZE){
      front = 0;
    }
    
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

void ShowQueue(){
  int i;
  
  printf("Queue:");
  for(i=0; i<QUEUE_SIZE; i++){
    if(queue[i]!=NO_DATA){
      printf("[%4d]", queue[i]);
    } else {
      printf("[  ]");
    }
  }
  printf("\n");
}
