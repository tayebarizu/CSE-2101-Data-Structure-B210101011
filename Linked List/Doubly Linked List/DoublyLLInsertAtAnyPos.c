#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node* prev;
  int data;
  struct node* next;
};

struct node* add_mpty(struct node* head, int d){
    struct node* temp = malloc(sizeof(struct node));

    temp->prev = NULL;
    temp->data = d;
    temp->next = NULL;
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

struct node* add_at_any_pos(struct node* head, int d, int pos){
 struct node* temp = malloc(sizeof(struct node));
 struct node* tp = head;

 temp->prev = NULL;
 temp->data = d;
 temp->next = NULL;

 while(pos!=1){
  tp = tp->next;
  pos--;
 }
 struct node* tp2 = tp->next;

 if(tp->next ==NULL){
    tp->next = temp;
    temp->prev = tp;
 }

 else{
 tp->next = temp;
 temp->prev = tp;

 temp->next = tp2;
 tp2->prev = temp;
 }

 return head;
}

int main(){
 struct node* head = malloc(sizeof(struct node));

 head = add_mpty(head,45);
  add_end(head, 34);
  add_end(head, 25);
  head = add_at_any_pos(head, 67, 3);

 struct node* ptr = head;

 while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr = ptr->next;
 }
 return 0;
}
