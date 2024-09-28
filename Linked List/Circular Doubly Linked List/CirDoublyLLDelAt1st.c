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

struct node* del_beg(struct node* tail){
 if(tail == NULL)
    return tail;

 struct node* temp = tail->next;
 if(temp == tail){
    free(tail);
    tail=NULL;
    return tail;
 }

 tail->next = temp->next;
 temp->next->prev = tail;
 free(temp);

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

 tail = del_beg(tail);

 printf("\nAfter Deletion: \n");
 print(tail);

 return 0;
}
