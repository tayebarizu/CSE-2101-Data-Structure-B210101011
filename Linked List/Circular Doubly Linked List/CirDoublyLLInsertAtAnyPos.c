#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node* prev;
  int data;
  struct node* next;
};

struct node* addToEmpty(int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->prev = temp;
  temp->data = d;
  temp->next = temp;
  return temp;
};

struct node* add_end(struct node* tail, int d){
  struct node* newN = addToEmpty(d);
  if(tail == NULL)
    return newN;
  struct node* temp = tail->next;
  newN->prev = tail;
  newN->next = temp;
  temp->prev = newN;
  tail->next = newN;
  tail = newN;

  return tail;
};

struct node* addAtAnyPos(struct node* tail, int d, int pos){
    struct node* newN = addToEmpty(d);
  struct node* temp = tail->next;
  if(tail==NULL)
    return newN;
  while(pos>1){
    temp = temp->next;
    pos--;
  }
  newN->prev = temp;
  newN->next = temp->next;
  temp->next->prev = newN;
  temp->next = newN;

  if(temp==tail)
    tail=tail->next;

  return tail;
};

void print(struct node* tail){
 if(tail == NULL)
    printf("The Linked List is Empty!!\n");
 else{
        struct node* p = tail->next;
    do{
      printf("%d ",p->data);
      p = p->next;
    }while(p!=tail->next);
 }
 printf("\n");
}

int main(){
 struct node* tail = malloc(sizeof(struct node));
 tail = addToEmpty(45);
 tail = add_end(tail,34);
 tail = add_end(tail,6);
 tail = addAtAnyPos(tail,66,3);

 print(tail);
}

