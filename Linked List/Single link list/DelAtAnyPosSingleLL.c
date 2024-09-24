#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *link;
};

struct node* add_end(struct node *ptr,int d){
   struct node *temp = malloc(sizeof(struct node));
   temp->data = d;
   temp->link = NULL;
   ptr->link = temp;

   return temp;
}

void delAnyPos(struct node **head, int pos){
   struct node *cur = *head;
   struct node *prev = *head;

   if(*head == NULL){
    printf("The Node is empty!!");
   }
   else if(pos==1){
    *head = cur->link;
    free(cur);
    cur = NULL;
   }
   else{
    while(pos!=1){
        prev = cur;
        cur = cur->link;
        pos--;
    }
    prev->link = cur->link;
    free(cur);
    cur=NULL;
   }
}

int main(){
 struct node *head = malloc(sizeof(struct node));
 head->data = 45;
 head->link = NULL;

 struct node *ptr = head;
 ptr = add_end(ptr,98);
 ptr = add_end(ptr,3);

 delAnyPos(&head,2);

 ptr=head;
 while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
 }
 }
