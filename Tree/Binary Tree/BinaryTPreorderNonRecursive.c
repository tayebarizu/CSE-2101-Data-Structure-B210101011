#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
 struct node* left;
 int data;
 struct node* right;
};
struct node* stack[MAX];
int top = -1;

int isEmpty(){
 if(top == -1)
    return 1;
 else
    return 0;
}

void push(struct node* d){
 if(top == MAX-1){
 printf("Stack overflow!\n");
 exit(1);
 }
 top++;
 stack[top] = d;
}

struct node* pop(){
 if(isEmpty()){
    printf("Stack underFlow!\n");
    exit(1);
 }
 struct node* temp;
 temp = stack[top];
 top--;
 return temp;
};

struct node* createT(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;
 return newN;
};

void preOrder(struct node* root){
 struct node* ptr = root;
 if(ptr == NULL){
    printf("It is an empty binary tree.\n");
    exit(1);
 }
 push(ptr);
 while(!isEmpty()){
    ptr = pop();
    printf("%d ", ptr->data);
 if(ptr->right != NULL)
    push(ptr->right);
 if(ptr->left != NULL)
    push(ptr->left);
 }
}

int main(){
 struct node* root = NULL;
 root = createT(1);
 root->left = createT(2);
 root->right = createT(3);
 root->left->left = createT(4);
 root->left->right = createT(5);
 root->left->right->left = createT(6);
 root->left->right->right = createT(7);

 preOrder(root);

 return 0;
}
