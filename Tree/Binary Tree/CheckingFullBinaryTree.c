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

int checkBinaryTree(struct node* root){
 if(root == NULL)
    return 1;
 if(root->left == NULL && root->right == NULL)
    return 1;
 if((root->left) && (root->right)){
    int left = checkBinaryTree(root->left);
    int right = checkBinaryTree(root->right);
    return (left && right);
 }
}

int main(){
 struct node* root = NULL;
 root = createT(1);
 root->left = createT(2);
 root->right = createT(3);
 root->left->left = createT(4);
 root->left->right = createT(5);

 if(checkBinaryTree(root))
    printf("The given binary tree is a full binary tree.");
 else
     printf("The given binary tree is not a full binary tree.");
 return 0;
}
