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

struct node* delAtAnyPos(struct node* tail,int pos){
  if(tail==NULL){
    return tail;
  }
  struct node* temp = tail->next;
  if(tail->next == tail){
    free(tail);
    tail = NULL;
    return tail;
  }
  while(pos>2){
    temp = temp->next;
    pos--;
  }
  struct node* temp2 = temp->next;
   temp->next = temp2->next;
  if(temp2 == tail)
    tail = temp;
    free(temp2);
    temp2 = NULL;
    return tail;
};

void print(struct node* tail){
    if(tail==NULL){
        printf("The list is empty!");
    }
    else{
      struct node* p = tail->next;
       do{
          printf("%d ",p->data);
          p = p->next;
       }while(p!=tail->next);
    }
}

int main(){
 struct node* tail = malloc(sizeof(struct node));
 tail = addToEmpty(34);
 tail = add_end(tail,45);
 tail = add_end(tail,6);
 tail = add_end(tail,23);

 printf("Before deletation:\n");
 print(tail);

 tail = delAtAnyPos(tail,1);
 printf("\nAfter deletion:\n");
 print(tail);
}

