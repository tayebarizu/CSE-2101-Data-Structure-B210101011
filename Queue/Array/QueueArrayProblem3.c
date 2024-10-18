//Write a program to reverse a stack using queue.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int queue[MAX];
int front = -1;
int rear = -1;
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
    printf("Stack overflow!");
    exit(1);
 }
 top++;
 stack[top] = d;
}

int pop(){
 if(isEmpty()){
    printf("Stack Underflow!");
    exit(1);
 }
 int data;
 data = stack[top];
 top--;
 return data;
}

void enQ(int d){
 if(front == -1)
    front = 0;
 rear++;
 queue[rear] = d;
}

int deQ(){
 int data = queue[front];
 front++;
 return data;
}

void reverseStack(){
 while(!isEmpty()){
    enQ(pop());
 }
 while(!(front == -1 || front == rear+1)){
    push(deQ());
 }
}

void print(){
 if(isEmpty()){
    printf("Stack Underflow!");
    exit(1);
 }
 for(int i = top; i>=0; i--){
    printf("%d ",stack[i]);
 }
 printf("\n");
}

int main(){
 push(10);
 push(20);
 push(30);
 push(40);

 printf("Before reverse : ");
 print();

 printf("After reverse : ");
 reverseStack();
 print();
}
