#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node*  add_end(struct node *head, int d){
  struct node *ptr = malloc(sizeof(struct node));
  ptr->data = d;
  ptr->link = NULL;
  head->link = ptr;

  return ptr;
}

struct node* del_first(struct node *head){
    if(head==NULL){
        printf("The list is Empty!!");
    }
    struct node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}

int main(){
   struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_end(ptr,98);
    ptr = add_end(ptr,3);

    head = del_first(head);
    ptr = head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
