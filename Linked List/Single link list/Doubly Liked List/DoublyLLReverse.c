#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* prev;
 int data;
 struct node* next;
};

struct node* add_empty(struct node* head, int d){
  struct node* temp = malloc(sizeof(struct node));

  temp->prev = NULL;
  temp->data = d;
  temp->next = NULL;

  head = temp;

  return head;
};

void add_end(struct node* head, int d){
  struct node* temp = malloc(sizeof(struct node));

  temp->prev = NULL;
  temp->data = d;
  temp->next = NULL;

  struct node* tp = head;

  while(tp->next!=NULL){
    tp=tp->next;
  }
  tp->next = temp;
  temp->prev = tp;
}

struct node* revNode(struct node* head){
  struct node* ptr1 = head;
  struct node* ptr2 = ptr1->next;

  ptr1->next = NULL;
  ptr1->prev = ptr2;

  while(ptr2!=NULL){
    ptr2->prev = ptr2->next;
    ptr2->next = ptr1;
    ptr1=ptr2;
    ptr2=ptr2->prev;
  }
  head = ptr1;
  return head;
}


void print(struct node* head){
  struct node* ptr = head;
  while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr=ptr->next;
  }
 }

 int main(){
  struct node* head = NULL;
  head = add_empty(head,45);
  add_end(head,34);
  add_end(head,9);

  printf("Print before reverse: \n");
  print(head);

   head = revNode(head);
   printf("\nPrint After reverse: \n");
   print(head);
 }


