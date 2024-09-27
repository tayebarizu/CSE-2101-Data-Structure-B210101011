#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* prev;
 int data;
 struct node* next;
};

struct node* add_empty(struct node* head, int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->prev =NULL;
  temp->data = d;
  temp->next = NULL;

  head = temp;

  return head;
};

void add_end(struct node* head, int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = d;
  temp ->next = NULL;

  struct node* tp = head;

  while(tp->next!=NULL){
    tp = tp->next;
  }
  tp->next = temp;
  temp->prev = tp;
}

struct node* createList(struct node* head){
  int data, i,n;
  printf("Enter the number of nodes: ");
  scanf("%d",&n);

  if(n==0)
    return head;

  printf("Enter the element for 1: ");
  scanf("%d",&data);
  head = add_empty(head,data);
  for(i=1;i<n;i++){
    printf("Enter the element for %d ", i+1);
    scanf("%d", &data);
    add_end(head,data);
  }
  return head;
};

int main(){
 struct node* head = NULL;
 struct node* ptr;

 head = createList(head);

 ptr = head;
 while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
 }
 return 0;
}
