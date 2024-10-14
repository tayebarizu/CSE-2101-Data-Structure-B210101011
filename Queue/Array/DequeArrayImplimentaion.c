#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

int isFull(){
 if((front == 0 && rear == MAX-1) ||(front == rear+1))
    return 1;
 else
    return 0;
}

int isEmpty(){
 if(front == -1)
    return 1;
 else
    return 0;
}
void enQFront(int d){
 if(isFull()){
    printf("Queue Overflow");
    exit(1);
 }
 if(front == -1){
    front = 0;
    rear = 0;
 }
 else if(front == 0)
    front = MAX-1;
 else
    front--;
 deque[front] = d;
}

void enQRear(int d){
  if(isFull()){
    printf("Queue Overflow");
    exit(1);
 }
 if(front == -1){
    front = 0;
    rear = 0;
 }
 else if(rear == MAX-1)
    front = 0;
 else
    rear++;
 deque[rear] = d;
}

int deQfront(){
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 int data = deque[front];
 if(front == MAX-1)
    front = 0;
 else if(rear == front){
    front = -1;
    rear = -1;
 }
 else
    front++;
 return data;
}

int deQRear(){
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 int data = deque[rear];
 if(rear == 0)
    front = MAX-1;
 else if(rear == front){
    front = -1;
    rear = -1;
 }
 else
    rear--;
 return data;
}

int peek(){
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 return deque[front];
}

void print(){
 if(isEmpty()){
    printf("Queue underflow!");
    exit(1);
 }
 int temp = front;
 if(front <= rear){
    while(temp <= rear){
        printf("%d ",deque[temp]);
        temp++;
    }
 }
 else{
    while(temp <= MAX-1){
         printf("%d ",deque[temp]);
         temp++;
    }
    temp = 0;
    while(temp <= rear){
        printf("%d ",deque[temp]);
        temp++;
    }
 }
 printf("\n");
}

int main(){
 int data, choice;
 while(1){
    printf("1.Insert at front.\n");
    printf("2.Insert at rear.\n");
    printf("3.Delete from front.\n");
    printf("4.Delete from rear.\n");
    printf("5.Print first element of queue.\n");
    printf("6.Print all the element.\n");
    printf("7.Quit.\n");

    printf("Enter a choice : ");
    scanf("%d",&choice);

    switch(choice){
 case 1:
     printf("Enter an element to be inserted at front: ");
     scanf("%d",&data);
     enQFront(data);
     printf("The element is inserted at front successfully.\n");
     break;
 case 2:
     printf("Enter an element to be inserted at rear: ");
     scanf("%d",&data);
     enQRear(data);
     printf("The element is inserted at rear successfully.\n");
     break;
 case 3:
     data = deQfront();
     printf("Deleted an element from front : %d\n", data);
     break;
 case 4:
     data = deQRear();
     printf("Deleted an element from rear : %d\n", data);
     break;
 case 5:
     printf("The first element is : %d \n",peek());
     break;
 case 6:
     printf("Queue : \n");
     print();
     break;
 case 7:
     exit(1);
 default:
    printf("Wrong decision!\n");

    }
 }
}

