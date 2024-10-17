//Write a program to reverse all the elements of the queue using one stack.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int stack[MAX];

int front = -1;
int rear = -1;
int top = -1;

int isFull(){
 if(rear == MAX-1)
    return 1;
 else
    return 0;
}

int isEmpty(){
 if(front == -1 || front == rear+1)
    return 1;
 else
    return 0;
}

void enQ(int d){
  if(isFull()){
    printf("Queue Overflow!");
    exit(1);
  }
  if(front == -1)
    front = 0;
  rear++;
  queue[rear] = d;
}

int deQ(){
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 int data;
 data = queue[front];
 front++;
 return data;
}

void push(int d){
 top++;
 stack[top] = d;
}

int pop(){
 int data = stack[top];
 top--;
 return data;
}

void reverseQ(){
 while(!isEmpty()){
    push(deQ());
 }
 front = rear = -1;
 while(top != -1){
    enQ(pop());
 }
}

void print(){
 int i;
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 for(i=front; i<= rear; i++){
    printf("%d ", queue[i]);
 }
 printf("\n");
}

int main(){
 enQ(10);
 enQ(20);
 enQ(30);
 enQ(40);

 printf("Before reverse : ");
 print();

 printf("After reverse : ");
 reverseQ();
 print();
}
