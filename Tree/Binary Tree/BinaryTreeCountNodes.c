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

int countNodes(struct node* root){
 if(root == NULL){
    return 0;
 }
 else if(root->left == NULL && root->right == NULL)
    return 1;
 else{
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return (left+right+1);
 }
}

int main(){
 struct node* root = NULL;
 root = createT(10);
 root->left = createT(20);
 root->right = createT(30);
 root->left->left = createT(40);
 root->left->right = createT(50);
 root->right->left = createT(60);
 root->right->right = createT(70);

 printf("Total number of nodes in binary tree are : %d\n",countNodes(root));
 return 0;
}
