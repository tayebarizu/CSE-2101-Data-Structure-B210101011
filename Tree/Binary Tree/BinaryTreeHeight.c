#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createBT(char ch){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = ch;
 newN->right = NULL;

 return newN;
};

int heightBT(struct node* root){
 if(root == NULL)
    return 0;
 if(root->left == NULL && root->right == NULL)
    return 0;
 int left = heightBT(root->left);
 int right = heightBT(root->right);

 if(left>right)
    return left+1;
 else
    return right+1;
}

int main(){
 struct node* root = NULL;
 root = createBT('a');
 root->left = createBT('b');
 root->right = createBT('e');
 root->left->left = createBT('c');
 root->left->right = createBT('d');
 root->right->left = createBT('f');
 root->left->left->left = createBT('g');

 int height = heightBT(root);
 printf("%d ", height);

 return 0;
}
