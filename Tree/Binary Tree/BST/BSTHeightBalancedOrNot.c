#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createBT(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;
 return newN;
};

int heightBT(struct node* root){
 if(root == NULL)
    return -1;
 if(root->left == NULL && root->right == NULL)
    return 0;
 int left = heightBT(root->left);
 int right = heightBT(root->right);

 if(left>right)
   return left + 1;
 else
   return right + 1;
}

int isBalanced(struct node* root){
 int l = 0, r = 0, lh = 0, rh = 0, diff = 0;
 if(root == NULL)
    return 1;
 l = isBalanced(root->left);
 r = isBalanced(root->right);
 if(l && r){
    lh = heightBT(root->left);
    rh = heightBT(root->right);
    diff = abs((lh+1) - (rh+1));
    if(diff<=1)
        return 1;
 }
 return 0;
}

int main(){
 struct node* root = NULL;
 root = createBT(50);
 root->left = createBT(40);
 root->right = createBT(60);
 root->right->left = createBT(55);

 if(isBalanced(root)){
    printf("Binary Tree is balanced height.");
 }
 else{
    printf("Binary Tree is not balanced height.");
 }

 return 0;
}
