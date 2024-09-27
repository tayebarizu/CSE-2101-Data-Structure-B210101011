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
}

struct node* add_begin(struct node* head, int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = d;
  temp->next = NULL;

  temp->next = head;
  head->prev = temp;
  head = temp;

  return head;
}

void add_end(struct node* head, int d){
 struct node* temp = malloc(sizeof(struct node));
 temp->prev = NULL;
 temp->data = d;
 temp->next = NULL;

 struct node* tp = head;

   while(tp->next!=NULL){
    tp = tp->next;
   }
   tp->next = temp;
   temp->prev = tp;
}

int main(){
 struct node* head = NULL;
 struct node* ptr;

 head = add_empty(head, 45);
 head = add_begin(head,34);
 add_end(head,9);

 ptr = head;
 while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
 }
 return  0;
}
