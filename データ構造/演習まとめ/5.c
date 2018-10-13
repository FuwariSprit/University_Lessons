#include<stdio.h>
int top =-1;
int stack[10];

int Push(int data);
int Pop(void);

int main(void){
  char data[10];
  int x, y, i = 0;

  for(i=0; i<10; i++){
    data[i] = '\0';
  }
  for(i=0; i<10; i++){
    stack[i] = -1; 
  }

  printf("逆ポーランド記法で記述された数式を入力してください\n");
  scanf("%s", data);
  i = 0;
  while(1){
    if(data[i]=='+'){
      x = Pop();
      y = Pop();
      Push(x+y);
    }
    else if(data[i] == '-'){
      x = Pop();
      y = Pop();
      Push(y-x);
    }
    else if(data[i] == '*'){
      x = Pop();
      y = Pop();
      Push(x*y);
    }
    else {
      Push((int)data[i] - '0');
    }
    i++;
    if(i == 10){
      break;
    }
  }
  
  printf("計算結果 = %d\n", stack[0]);

  return 0;
}

int Push(int data){
  top++;
  if(top == 10){
    top--;
    return -1;
  } else {
    stack[top] = data;
    return 0;
  }
}

int Pop(void){
  if(top < 0){
    return -1;
  } else {
    int data = stack[top];
    top--;
    return data;
  }
}
