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

int isCompleteBinaryTree(struct node* root, int i, int count){
 if(root == NULL)
    return 1;
 if(i>= count)
    return 0;
 int left = isCompleteBinaryTree(root->left,2*i+1,count);
 int right = isCompleteBinaryTree(root->right,2*i+2,count);
 return (left && right);
}

int main(){
 struct node* root = NULL;
 root = createT(10);
 root->left = createT(20);
 root->right = createT(30);

 int count = countNodes(root);
 int index = 0;

 if(isCompleteBinaryTree(root,index,count))
     printf("The binary tree is a complete binary tree.\n");
 else
     printf("The binary tree is not a complete binary tree.\n");
 return 0;
}
