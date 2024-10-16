#include<stdio.h>
#include<stdlib.h>

struct node{
 int priority;
 int data;
 struct node* link;
}*front = NULL;

int isEmpty(){
 if(front == NULL)
    return 1;
 else
    return 0;
}

void enQ(int d,int prio){
 struct node* temp;
 struct node* newN = malloc(sizeof(struct node));

 if(newN == NULL){
    printf("Queue is overflow!");
    exit(1);
 }

 newN->priority = prio;
 newN->data = d;
 newN->link = NULL;

 if(isEmpty() || prio < front->priority){
    newN->link = front;
    front = newN;
 }
 else{
    temp = front;
    while(temp->link != NULL && temp->link->priority <= prio)
    temp = temp->link;
    newN->link = temp->link;
    temp->link = newN;
 }
}

int deQ(){
 int data;
 struct node* temp;
 if(isEmpty()){
        printf("Queue underflow!");
        exit(1);
 }
 else{
    temp = front;
    data = temp->data;
    front = front->link;
    free(temp);
    temp = NULL;
 }
 return data;
}

int peek(){
 if(isEmpty()){
        printf("Queue underflow!");
        exit(1);
 }
 return front->data;
}

void print(){
 if(isEmpty()){
        printf("Queue underflow!");
        exit(1);
 }
 else{
    struct node* temp = front;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
 }
 printf("\n");
}

int main(){
 int data, prio, choice;
 while(1){
    printf("1.Insert.\n");
    printf("2.Delete.\n");
    printf("3.Print the first element\n");
    printf("4.Print all the element.\n");
    printf("5.Quit.\n");

    printf("Enter a choice : ");
    scanf("%d",&choice);

    switch(choice){
case 1:
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    printf("Enter its priority : ");
    scanf("%d",&prio);
    enQ(data,prio);
    printf("The element inserted successfully.\n");
    break;
case 2:
    data = deQ();
    printf("Deleted element is : %d\n",data);
    break;
case 3:
    printf("The first element is : %d\n",peek());
    break;
case 4:
    printf("Queue : \n");
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
