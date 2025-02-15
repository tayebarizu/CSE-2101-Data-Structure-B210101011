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

struct node* rightRotate(struct node* B){
 struct node* A = B->left;
 B->left = A->right;
 A->right = B;
 return A;
};

int main(){
 struct node* root = NULL;
 root = createNode(70);
 root->left = createNode(54);
 root->left->left = createNode(35);
 root->left->right = createNode(59);
 root->left->left->left = createNode(29);
 root->left->left->right = createNode(45);
 root->right = createNode(75);
 root->right->right = createNode(80);
 root->left->left->left->left = createNode(15);

 printf("%d ",root->left->data);
 printf("%d ",root->left->left->data);
 printf("%d ",root->left->right->data);

 root->left = rightRotate(root->left);

 printf("\nAfter Rotation:\n");

 printf("%d ",root->left->data);
 printf("%d ",root->left->left->data);
 printf("%d ",root->left->right->data);
 printf("%d ",root->left->right->left->data);
 printf("%d ",root->left->right->right->data);

 return 0;
}

