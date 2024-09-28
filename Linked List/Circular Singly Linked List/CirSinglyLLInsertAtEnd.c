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
  struct node* newN = malloc(sizeof(struct node));
  newN->data = d;
  newN->next = NULL;
  tail->next = newN;
  newN->next = tail;
  tail = newN;

  return tail;
};

void print(struct node* tail){
  struct node* ptr = tail->next;
  do{
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }while(ptr!=tail->next);
}

int main(){
 struct node* tail = malloc(sizeof(struct node));
 tail = addToEmpty(45);

 tail = add_end(tail,56);
 print(tail);

 return 0;
}
