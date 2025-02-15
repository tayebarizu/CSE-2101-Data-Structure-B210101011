#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
 if(front == -1 || front == rear+1)
    return 1;
 else
    return 0;
}

void enQ(struct node* data){
  if(rear == MAX-1){
    printf("Queue overflow.\n");
    exit(1);
  }
  if(front == -1)
    front = 0;
  rear++;
  queue[rear] = data;
}

struct node* deQ(){
 if(isEmpty()){
    printf("Queue underflow.\n");
    exit(1);
 }
 struct node* d = queue[front];
 front++;
 return d;
};

struct node* createT(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;
 return newN;
};

void levelorder(struct node* root){
 struct node* ptr = root;
 if(root == NULL){
    printf("Given binary tree is empty.\n");
    return;
 }
  enQ(ptr);
  while(!isEmpty()){
    ptr = deQ();
    printf("%d ", ptr->data);
    if(ptr->left != NULL)
        enQ(ptr->left);
    if(ptr->right != NULL)
        enQ(ptr->right);
  }
}

int main(){
 struct node* root = NULL;
 root = createT(1);
 root->left = createT(2);
 root->right = createT(3);
 root->right->left = createT(4);
 root->right->right = createT(5);

 levelorder(root);

 return 0;
}
