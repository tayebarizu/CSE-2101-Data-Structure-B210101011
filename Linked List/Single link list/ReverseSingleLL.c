#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node* add_end(struct node *ptr, int d){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    ptr->link = temp;

    return temp;
}

 struct node* rev_list(struct node *head){
   struct node *temp = NULL;
   struct node *temp2 = NULL;

   while(head!=NULL){
    temp2 = head->link;
    head->link = temp;
    temp = head;
    head = temp2;
   }
   head = temp;
   return head;
}

int main(){
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *ptr = head;
  ptr = add_end(ptr,98);
  ptr = add_end(ptr,3);

  head = rev_list(head);

  ptr = head;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
  }
}
