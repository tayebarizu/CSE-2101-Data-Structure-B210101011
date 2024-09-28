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

struct node* add_beg(struct node* tail, int d){
  struct node* newN = addToEmpty(d);
  if(tail == NULL)
    return newN;
  struct node* temp = tail->next;
  newN->next = temp;
  newN->prev = tail;
  temp->prev = newN;
  tail->next = newN;

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
 tail = add_beg(tail,34);

 print(tail);
}
