#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createNode(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;
 return newN;
};

struct node* leftRotate(struct node* A){
 struct node* B = A->right;
 A->right = B->left;
 B->left = A;
 return B;
};

struct node* rightRotate(struct node* B){
 struct node* A = B->left;
 B->left = A->right;
 A->right = B;
 return A;
};

int main(){
 struct node* root = NULL;
 root = createNode(51);
 root->left = createNode(35);
 root->left->left = createNode(26);
 root->left->right = createNode(42);
 root->left->left->left = createNode(15);
 root->left->left->right = createNode(30);
 root->right = createNode(75);
 root->right->right = createNode(89);
 root->left->left->right->right = createNode(32);

 printf("%d ",root->left->data);
 printf("%d ",root->left->left->data);
 printf("%d ",root->left->right->data);

 root->left->left = leftRotate(root->left->left);
 root->left = rightRotate(root->left);

 printf("\nAfter Rotation:\n");

 printf("%d ",root->left->data);
 printf("%d ",root->left->left->data);
 printf("%d ",root->left->right->data);
 printf("%d ",root->left->left->left->data);
 printf("%d ",root->left->right->left->data);
 printf("%d ",root->left->right->right->data);

 return 0;
}

