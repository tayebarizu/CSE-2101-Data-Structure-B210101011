#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node* add_end(struct node *ptr,int d){
  struct node *temp = malloc(sizeof(struct node));
  temp->data = d;
  temp->link = NULL;
  ptr->link = temp;
  return temp;
}

struct node* del_nodes(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}
int main(){
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *ptr = head;
  ptr = add_end(ptr,98);
  ptr = add_end(ptr,3);
  head = del_nodes(head);
  if(head==NULL){
    printf("The Node is Empty!!");
  }
  else{
    printf("The node is not Empty.");
  }
}
