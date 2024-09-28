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

  newN->next = tail->next;
  tail->next = newN;
  tail = newN;

  return tail;
};

void print(struct node* tail){
 struct node* p = tail->next;
 do{
    printf("%d ",p->data);
    p = p->next;
 }while(p!=tail->next);
}

struct node* del1stNode(struct node* tail){
    if(tail == NULL){
        return tail;
    }
    else if(tail->next == tail){
        free(tail);
        tail=NULL;
        return NULL;
    }
  struct node* temp;
  temp = tail->next;
  tail->next = temp->next;
  free(temp);
  temp = NULL;
  return tail;
};

int main(){
 struct node* tail = malloc(sizeof(struct node));
 tail = addToEmpty(34);
   tail = add_end(tail,45);
   tail = add_end(tail,6);
   tail = add_end(tail,23);

 printf("Before deletation:\n");
 print(tail);

 tail = del1stNode(tail);
 printf("\nAfter deletation:\n");
 print(tail);
}
