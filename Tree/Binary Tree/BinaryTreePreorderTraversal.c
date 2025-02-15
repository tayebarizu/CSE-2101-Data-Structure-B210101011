#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createT(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;

 return newN;
};

void preorder(struct node* root){
 if(root == NULL)
    return;
 printf("%d ", root->data);
 preorder(root->left);
 preorder(root->right);
}

int main(){
 struct node* root = NULL;
 root = createT(1);
 root->left = createT(2);
 root->right = createT(3);
 root->left->left = createT(4);
 root->left->right = createT(5);
 root->right->right = createT(6);
 root->left->right->left = createT(7);
 root->left->right->right = createT(8);
 root->right->right->left = createT(9);

 preorder(root);

 return 0;
}
