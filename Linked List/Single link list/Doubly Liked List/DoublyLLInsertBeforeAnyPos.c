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
void addEnd(struct node* head, int d){
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

struct node* add_before_pos(struct node* head, int d, int pos){
  struct node* newN = malloc(sizeof(struct node));

  newN->prev = NULL;
  newN->data = d;
  newN->next = NULL;

  struct node* tp = head;
  struct node* tp2 = NULL;

  if(pos==1){
    newN->next = tp;
    tp->prev = newN;
    head = newN;
  }
  else{
    while(pos>2){
        tp = tp->next;
        pos--;
    }
    tp2 = tp->next;
    tp->next = newN;
    newN->prev = tp;
    tp2->prev = newN;
    newN->next = tp2;
  }
  return head;

}

int main(){
 struct node* head = malloc(sizeof(struct node));

 head = add_empty(head,45);
 addEnd(head,34);
 addEnd(head,25);
 head = add_before_pos(head,67,3);

 struct node* ptr = head;

 while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr=ptr->next;
 }
}
