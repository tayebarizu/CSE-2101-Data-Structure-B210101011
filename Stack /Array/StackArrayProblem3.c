//Decimal to Bianary conversion using stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isFull(){
 if(top == MAX-1)
    return 1;
 else
    return 0;
}

int isEmpty(){
 if(top == -1)
    return 1;
 else
    return 0;
}

void push(int d){
 if(isFull()){
    printf("The stack is overflow!!");
    return;
 }
 top++;
 stack[top] = d;
}

int pop(){
 if(isEmpty()){
    printf("The stack is underflow!!");
    exit(1);
 }
 int val;
 val = stack[top];
 top--;
 return val;
}

void decToBin(int n){
  while(n!=0){
    push(n%2);
    n = n/2;
  }
}

void print(){
 if(isEmpty()){
    printf("The stack is underflow!!");
    exit(1);
 }
 while(!isEmpty()){
    printf("%d ", pop());
 }
}

int main(){
 int dec;
 printf("Enter a decimal Number: ");
 scanf("%d",&dec);

 decToBin(dec);
 print();

 return 0;
}
