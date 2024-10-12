#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

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

void enQ(int data){
 if(isFull()){
    printf("The queue is overflow.");
    exit(1);
 }
 if(front == -1)
 front = 0;
 rear++;
 queue[rear] = data;
}

int deQ(){
 if(isEmpty()){
    printf("The queue is underflow.");
    exit(1);
 }
 int data;
 data = queue[front];
 front++;
 return data;
}

int peek(){
  if(isEmpty()){
    printf("The queue is underflow.");
    exit(1);
 }
 return queue[front];
}

void print(){
 if(isEmpty()){
    printf("The queue is underflow.");
    exit(1);
 }
 for(int i = front; i<=rear; i++){
    printf("%d ", queue[i]);
 }
 printf("\n");
}

int main(){
 int data, choice;
 while(1){
    printf("1.Enqueue.\n");
    printf("2.Dequeue.\n");
    printf("3.Print the first element.\n");
    printf("4.Print the all element.\n");
    printf("5.Quit.\n");

    printf("Enter a choice : ");
    scanf("%d", &choice);

    switch(choice){
 case 1:
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    enQ(data);
    printf("The element is inserted successfully.\n");
    break;
     case 2:
         data = deQ();
         printf("The deleted element is: %d\n",data);
         break;
     case 3:
         printf("The first element is: %d\n",peek());
         break;
     case 4:
         printf("All the elements are: \n");
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
