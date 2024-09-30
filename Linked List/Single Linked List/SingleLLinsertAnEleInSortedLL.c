#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

struct node* addToEmpty(int d){
 struct node* temp = malloc(sizeof(struct node));

 temp->data = d;
 temp->link = NULL;

 return temp;
};

struct node* add_end(struct node* head, int d){
 struct node* newN = addToEmpty(d);

 struct node* temp = head;
 while(temp->link != NULL)
    temp = temp->link;
 temp->link = newN;

 return head;
 };

struct node* insert(struct node* head, int d){
 struct node* newN = addToEmpty(d);
 struct node* temp;
 int key = d;

 if(head==NULL || key < head->data){
    newN->link = head;
    head = newN;
 }

 else{
    temp = head;
    while(temp->link!=NULL && temp->link->data < key)
        temp = temp->link;
    newN->link = temp->link;
    temp->link = newN;
 }

 return head;
};

void print(struct node* head){
 struct node* ptr = head;
 while(ptr != NULL){
    printf("%d ", ptr->data);
    ptr = ptr->link;
 }
 printf("\n");
}

int main(){
 struct node* head = NULL;
 head = addToEmpty(24);
 head = add_end(head, 45);
 head = add_end(head, 56);
 head = add_end(head, 100);

 head = insert(head,40);
 print(head);

 return 0;
}
