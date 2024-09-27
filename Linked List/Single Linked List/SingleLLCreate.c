#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

int main(){
  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *curr = malloc(sizeof(struct node));
  curr->data = 38;
  curr->link = NULL;
  head->link = curr;

  curr = malloc(sizeof(struct node));
  curr->data = 3;
  curr->link = NULL;
  head->link->link = curr;

  return 0;
}
