#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
}*front = NULL, *rear = NULL;

int isEmpty(){
 if(front == NULL)
    return 1;
 else
    return 0;
}

void enQ(int d){
 struct node* newN = malloc(sizeof(struct node));
 if(newN == NULL){
    printf("No space!");
    exit(1);
 }
 newN->data = d;
 newN->link = NULL;
 if(rear == NULL)
    rear = front = newN;
 else{
    rear->link = newN;
    rear = newN;
 }
}

int deQ(){
  if(isEmpty()){
        printf("Queue is Underflow.");
        exit(1);
    }
 struct node* temp = front;
 int data;
 data = temp->data;
 front = temp->link;
 free(temp);
 temp = NULL;
 return data;
}

int peek(){
 if(isEmpty()){
        printf("Queue is Underflow.");
        exit(1);
    }
    return front->data;
}

void print(){
 if(isEmpty()){
        printf("Queue is Underflow.");
        exit(1);
    }
    struct node* temp = front;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
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
