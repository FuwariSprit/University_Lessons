#include<stdio.h>
#include<stdlib.h>

#define MAX 2000
#define FMAX 20

int lin_c = 0, bin_c = 0;

void swap(int *x, int *y);
void quick(int x[], int left, int right);
int bin_search(int a[], int n, int key);
int lin_search(int a[], int n, int key);

int main(void){
  int i;
  int seisu[MAX];
  int kosu, ky, idx0, idx1;
  char fname[FMAX];
  FILE *fp;

  kosu = MAX;
  printf("Input file name:");
  scanf("%s", fname);

  fp = fopen(fname, "r");

  if(fp == NULL){
    printf("No file found!");
    exit (1);
  }

  for(i=0; i<kosu; i++){
    fscanf(fp, "%d\n", &seisu[i]);
  }

  printf("Number to search:");
  scanf("%d", &ky);

  idx0 = lin_search(seisu, kosu, ky);
  if(idx0 == -1)
    exit(1);

  quick(seisu, 0, MAX-1);
  idx1 = bin_search(seisu, kosu, ky);
  if(idx1 == -1)
    exit(1);

  printf("lin_search comp count %d\n", lin_c);
  printf("bin_search comp count %d\n", bin_c);

  fclose(fp);

  return 0;
}

void swap(int *x, int *y){
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void quick(int x[], int left, int right){
  int pl = left;
  int pr = right;
  int pivot = x[(pl + pr) / 2];

  while(1){
    while(x[pl] < pivot){
      pl++;
    }
    while(x[pr] > pivot){
      pr--;
    }
    if(pr < pl){
      break;
    }

    swap(&x[pl], &x[pr]);
    pl++;
    pr--;
  }
  
  if(left < pr){
    quick(x, left, pr);
  }
  if(right > pl){
    quick(x, pl, right);
  }
}

int bin_search(int a[], int n, int key){
  int pl, pr, pc;
  
  pl = 0;
  pr = n-1;
  
  while(1){
    if(pr < pl){
      return -1;
    }
    
    pc = (pl+pr) / 2;
    
    if(a[pc] < key){
      pl = pc+1;
      bin_c++;
    }
    
    else if(key < a[pc]){
      pr = pc - 1;
      bin_c++;
    }
    
    else if(a[pc] == key){
      bin_c++;
      return pc;
    }
  }
}

int lin_search(int a[], int n, int key){
  int i = 0;

  while(1){

    lin_c++;

    if(i == n){
      return -1;
    }
    if(a[i] == key){
      return i;
    }
    i++;
  }
}
