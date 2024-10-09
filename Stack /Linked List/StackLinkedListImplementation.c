#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
}*top = NULL;

int isEmpty(){
 if(top == NULL)
    return 1;
 else
    return 0;
}

void push(int d){
 struct node* newN = malloc(sizeof(struct node));
 if(newN == NULL){
    printf("The stack is overflow!");
    exit(1);
 }
 newN->data = d;
 newN->link = NULL;

 newN->link = top;
 top = newN;
}

int pop(){
 if(isEmpty()){
    printf("The stack is underflow.");
    exit(1);
 }
 struct node* temp = top;
 int val = temp->data;
 top = top->link;
 free(temp);
 temp = NULL;
 return val;
}

int peek(){
if(isEmpty()){
    printf("The stack is underflow.");
    exit(1);
 }
 return top->data;
}

void print(){
 struct node* temp = top;

 if(isEmpty()){
    printf("The stack is underflow.");
    exit(1);
 }

 while(temp){
    printf("%d ", temp->data);
    temp = temp->link;
 }
 printf("\n");
}

int main(){
 int data, choice;
 while(1){
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Print the top most element.\n");
    printf("4. Print all the element.\n");
    printf("5. Quit.\n");

    printf("Enter a choice: ");
    scanf("%d",&choice);

    switch(choice){
    case 1:
         printf("Enter the element to be pushed: ");
         scanf("%d",&data);
         push(data);
         break;
    case 2:
         printf("The deleted element is: %d \n",pop());
         break;
    case 3:
        printf("The top most element is : %d\n",peek());
        break;
    case 4:
       printf("All the elements are: \n");
       print();
       break;
    case 5:
       exit(1);
    default:
       printf("wrong choice Entered.\n");
    }
}
return 0;
}
