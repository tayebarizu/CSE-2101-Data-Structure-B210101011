#include<stdio.h>
#include<stdlib.h>
#define MAX 7

int cq[MAX];
int front = -1;
int rear = -1;

int isFull(){
 if((front == 0 && rear == MAX-1) || (front == rear+1))
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

void enQ(int d){
 if(isFull()){
    printf("The Queue is overflow.");
    exit(1);
 }
 if(front == -1)
     front = 0;
 if(rear == MAX-1)
       rear = 0;
 else
    rear++;
 cq[rear] = d;
}

int deQ(){
 if(isEmpty()){
    printf("The Queue is underflow.");
    exit(1);
 }
 int d = cq[front];
 if(front == rear)
    front = rear = -1;
 else if(front == MAX-1)
    front = 0;
 else
    front++;
 return d;
}

int peek(){
 if(isEmpty()){
    printf("The Queue is underflow.");
    exit(1);
 }
 return cq[front];
}

void print(){
 int temp;
 if(isEmpty()){
    printf("The Queue is underflow.");
    exit(1);
 }
 temp = front;
 if(front <= rear){
    while(temp <= rear){
        printf("%d ",cq[temp]);
        temp++;
    }
 }
 else{
    while(temp <= MAX-1){
        printf("%d ",cq[temp]);
        temp++;
    }
    temp = 0;
    while(temp <= rear){
        printf("%d ",cq[temp]);
        temp++;
    }
 }
 printf("\n");
}

int main(){
 int choice, data;
 while(1){
    printf("1.Insert.\n");
    printf("2.Delete.\n");
    printf("3.Print the first element.\n");
    printf("4.Print all the element.\n");
    printf("5.Quit.\n");

    printf("Enter a choice : ");
    scanf("%d",&choice);

    switch(choice){
 case 1:
    printf("Enter a element to be inserted: ");
    scanf("%d",&data);
    enQ(data);
    printf("The element is entered successfully.\n");
    break;
 case 2:
        printf("The deleted element is : %d\n",deQ());
        break;
 case 3:
         printf("The first element is : %d\n",peek());
         break;
 case 4:
     printf("THE QUEUE IS : \n");
     print();
     break;
 case 5:
     exit(1);
 default:
    printf("Wrong choice.\n");
    }
 }
 return 0;
}
