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

int main(){
 struct node* root = NULL;
 root = createNode(51);
 root->left = createNode(35);
 root->left->left = createNode(33);
 root->right = createNode(65);
 root->right->left = createNode(60);
 root->right->right = createNode(78);
 root->right->right->left = createNode(72);
 root->right->right->right = createNode(80);
 root->right->right->right->left = createNode(79);

 printf("%d ",root->right->data);
 printf("%d ",root->right->left->data);
 printf("%d ",root->right->right->data);

 root->right = leftRotate(root->right);

 printf("\nAfter Rotation:\n");

 printf("%d ",root->right->data);
 printf("%d ",root->right->left->data);
 printf("%d ",root->right->left->right->data);
 printf("%d ",root->right->right->data);

 return 0;
}
