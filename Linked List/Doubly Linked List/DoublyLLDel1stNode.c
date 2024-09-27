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

struct node* del1stNode(struct node* head){
  head = head->next;
  free(head->prev);
  head->prev = NULL;

  return head;
};

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

  printf("Print before deletation: \n");
  print(head);

  head = del1stNode(head);
   printf("\nPrint After deletation: \n");
   print(head);
 }
