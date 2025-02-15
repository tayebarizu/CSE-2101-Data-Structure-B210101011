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

struct node* insert_Rec(struct node* root, int key){
 if(root == NULL)
    root = createBT(key);
 else if(key<root->data)
    root->left = insert_Rec(root->left,key);
 else if(key>root->data)
    root->right = insert_Rec(root->right,key);
 else
    printf("Duplicate key!\n");
 return root;
 };

void printBst(struct node* root){
 if(root == NULL)
    return;
 printBst(root->left);
 printf("%d ", root->data);
 printBst(root->right);
}


int main(){
 struct node* root = NULL;
 root = createBT(67);
 root->left = createBT(34);
 root->right = createBT(80);
 root->left->left = createBT(10);
 root->left->right = createBT(55);
 root->left->right->left = createBT(45);
 root->left->right->right = createBT(60);

 root = insert_Rec(root,30);
 printBst(root);

 return 0;
}




