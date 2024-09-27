//using single pointer
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

void del_last(struct node *head){
   if(head==NULL){
    printf("The list is empty!!");
   }
   else if(head->link ==NULL){
    free(head);
    head=NULL;
   }

   else{
    struct node *temp = head;
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
   }
}

int main(){
 struct node *head = malloc(sizeof(struct node));
 head->data = 45;
 head->link = NULL;

 struct node *ptr = head;
 ptr = add_end(ptr,98);
 ptr = add_end(ptr,3);

 del_last(head);

 ptr=head;
 while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
 }
 }
