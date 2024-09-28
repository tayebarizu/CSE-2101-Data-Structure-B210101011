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
 if(tail==NULL)
    return newN;

 struct node* temp = tail->next;
 newN->prev = tail;
 newN->next = temp;
 temp->prev = newN;
 tail->next = newN;
 tail = newN;

 return tail;
};

struct node* delAtAnyPos(struct node* tail,int pos){
 if(tail == NULL)
    return tail;

  struct node* temp = tail->next;
  while(pos>1){
    temp = temp->next;
    pos--;
  }
  struct node* temp2 = temp->prev;
  temp2->next = temp->next;
  temp->next->prev = temp2;
  free(temp);
  if(temp == tail)
    tail = temp2;
    return tail;
};

void print(struct node* tail){
 if(tail == NULL)
    printf("Linked list is empty!!");

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
 struct node* tail = NULL;
 tail = addToEmpty(34);
 tail = add_end(tail,45);
 tail = add_end(tail,6);

 printf("Before Deletion:\n");
 print(tail);

 tail = delAtAnyPos(tail,3);

 printf("\nAfter Deletion: \n");
 print(tail);

 return 0;
}
