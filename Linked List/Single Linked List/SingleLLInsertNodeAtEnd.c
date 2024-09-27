#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
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

void insertAtEnd(struct node *head, int data){
  struct node *ptr, *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;
  ptr=head;
  while(ptr->link!=NULL){
    ptr = ptr->link;
  }
  ptr->link = temp;
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

  insertAtEnd(head,67);
  printData(head);
  return 0;
}

