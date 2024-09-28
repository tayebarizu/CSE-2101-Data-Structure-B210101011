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

struct node* createList(struct node* tail){
  int data,n,i;
  printf("Enter the number of Nodes: ");
  scanf("%d",&n);

  if(n==0){
    return tail;
  }

  printf("Enter the element of 1: ");
  scanf("%d", &data);
  tail = addToEmpty(data);

  for(i=1;i<n;i++){
    printf("Enter the element of %d ", i+1);
    scanf("%d", &data);
    tail= add_end(tail,data);
  }
  return tail;
};

void print(struct node* tail){
    if(tail==NULL){
        printf("The node is empty.");
    }
    else{
  struct node* ptr = tail->next;
  do{
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }while(ptr!=tail->next);
    }
}

int main(){
  struct node* tail = NULL;
  tail = createList(tail);
  print(tail);
}
