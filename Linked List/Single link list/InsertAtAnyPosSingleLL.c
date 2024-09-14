#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node* add_end(struct node *ptr, int data){
   struct node *temp = malloc(sizeof(struct node));
   temp->data=data;
   temp->link = NULL;
   ptr->link = temp;
   return temp;
}

void addAtAnyPos(struct node *head, int pos, int d){
  struct node *ptr = head;
  struct node *ptr2 = malloc(sizeof(struct node));
  ptr2->data = d;
  ptr2->link = NULL;
  //pos--;
  while(pos!=2){
    ptr = ptr->link;
    pos--;
  }
  ptr2->link = ptr->link;
  ptr->link = ptr2;
}

int main(){
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;
  struct node *ptr = head;
  ptr = add_end(ptr,98);
  ptr = add_end(ptr,3);
  int position = 3, data = 67;
  addAtAnyPos(head,position,data);
  ptr = head;

  while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}
