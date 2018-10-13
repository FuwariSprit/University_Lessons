#include<stdio.h>

#define QUEUE_SIZE 5
#define NO_DATA -1

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;
int num = 0;

void ShowQueue();
int EnQueue(int data);
int DeQueue();

int main(void){
  int i, jadge, state, data;

  for(i=0; i<QUEUE_SIZE; i++){
    queue[i] = NO_DATA;
  }

  while(1){
    printf("(1)Enqueue (2)Dequeue (0)Exit :");
    scanf("%d", &state);

    if(state==1){
      printf("Data:");
      scanf("%d", &data);
      jadge = EnQueue(data);
      if(jadge==-1){
	printf("Queue is full!\n");
	printf("Enqueue is failed!\n");
      }
      
    } else if(state==2){
      jadge = DeQueue();
      if(jadge==-1){
	printf("Queue is Empty!\n");
	printf("Dequeue is failed!\n");
      } else {
	printf("Dequeue data is %d\n", jadge);
      }
    } else if(state==0){
      break;
    }

    ShowQueue();
  }

  return 0;
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
