//Reverse a stack using two stack
#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

int isEmpty(struct node* top){
 if(top == NULL)
    return 1;
 else
    return 0;
}

void push(int d, struct node** top1){
 struct node* newN = malloc(sizeof(struct node));
 if(newN == NULL){
    printf("The stack is overflow.");
    exit(1);
 }

 newN->data = d;
 newN->link = NULL;

 newN->link = *top1;
 *top1 = newN;
}

int pop(struct node** top1){
 if(isEmpty(*top1)){
    printf("The stack is underflow.");
    exit(1);
 }
 struct node* temp = *top1;
 int val = temp->data;
 *top1 = (*top1)->link;
 free(temp);
 temp = NULL;

 return val;
 }

void rev_stack(struct node** top){
  struct node* top1 = NULL;
  struct node* top2 = NULL;

  while(*top != NULL){
    push(pop(top),&top1);
  }
  while(top1 != NULL){
    push(pop(&top1),&top2);
  }
  while(top2 != NULL){
    push(pop(&top2),top);
  }
}

void print(struct node* top){
 if(isEmpty(top)){
    printf("The stack is underflow.");
    exit(1);
 }
 struct node* temp = top;
 while(temp){
    printf("%d ", temp->data);
    temp = temp->link;
 }
 printf("\n");
}

int main(){
 struct node* top = NULL;

  push(1,&top);
  push(2,&top);
  push(3,&top);
  print(top);

  rev_stack(&top);
  printf("After reverse the stack: \n");
  print(top);
}
