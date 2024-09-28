#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* addToEmpty(int d){
 struct node* temp = malloc(sizeof(struct node));

 temp->data = d;
 temp->next = temp;

 return temp;
};

struct node* add_end(struct node* tail, int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->data = d;
  temp->next = NULL;
  temp->next = tail->next;
  tail->next = temp;
  tail = tail->next;

  return tail;
};

void countEle(struct node* tail){
  struct node* temp = tail->next;
  int count = 0;
  while(temp!=tail){
    temp = temp->next;
    count++;
  }
  count++;
  printf("The Number of Nodes is : %d\n",count);
}

int main(){
  struct node* tail = malloc(sizeof(struct node));
  tail = addToEmpty(34);
  tail = add_end(tail,45);
  tail = add_end(tail,66);
  tail = add_end(tail,6);

  countEle(tail);

  return 0;
}
