#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
void insertNodeAtBegin(struct node **head, int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->link = NULL;

  ptr->link = *head;
  *head = ptr;
}
int main(){
  struct node *head = (struct node*)malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = 98;
  ptr->link = NULL;
  head->link = ptr;

  insertNodeAtBegin(&head,3);

  ptr = head;
  while(ptr!=NULL){
    printf("%d", ptr->data);
    ptr = ptr->link;
  }
  return 0;

}
