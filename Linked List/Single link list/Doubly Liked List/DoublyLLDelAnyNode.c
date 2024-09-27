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

struct node* delLastNode(struct node* head){
  struct node* tp = head;
  struct node* tp2 = NULL;
  while(tp->next!=NULL){
    tp=tp->next;
  }
  tp2 = tp->prev;
  tp2->next = NULL;
  free(tp);
  tp = NULL;

  return head;
}

struct node*  delAnyNode(struct node* head,int pos){
  struct node* temp = head;
  struct node* temp2 = head;

  if(pos==1){
    head = del1stNode(head);
    return head;
  }

  while(pos>1){
    temp=temp->next;
    pos--;
  }
  if(temp->next==NULL){
    head = delLastNode(head);
  }
  else{
  temp2->next = temp->next;
  temp->next->prev = temp2;
  free(temp);
  temp = NULL;
  }

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

   head = delAnyNode(head,1);
   printf("\nPrint After deletation: \n");
   print(head);
 }

