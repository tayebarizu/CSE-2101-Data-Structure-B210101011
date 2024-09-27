#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

void countingNodes(struct node *head){
    int count = 0;
   if(head == NULL){
    printf("Linked List is Empty");
   }
   struct node *ptr = NULL;
   ptr = head;
   while(ptr!=NULL){
    count++;
    ptr = ptr->link;
   }
   printf("The total number of nodes are: %d\n",count);
};

void printData(struct node *head){
   if(head == NULL){
    printf("Linked List is Empty.");
   }
   struct node *ptr = NULL;
   ptr = head;
   while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr = ptr->link;
   }
}
int main(){
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *curr = malloc(sizeof(struct node));
  curr->data = 38;
  curr->link = NULL;
  head->link = curr;

  curr = malloc(sizeof(struct node));
  curr->data = 3;
  curr->link = NULL;
  head->link->link = curr;

  countingNodes(head);
  printData(head);
  return 0;
}
