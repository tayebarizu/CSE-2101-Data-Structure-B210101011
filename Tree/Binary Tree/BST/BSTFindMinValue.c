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

struct node* nonRecMin(struct node* root){
 if(root != NULL){
    while(root->left != NULL)
        root = root->left;
 }
 return root;
};


int main(){
 struct node* root = NULL;
 root = createBT(67);
 root->left = createBT(34);
 root->right = createBT(80);
 root->left->left = createBT(10);
 root->left->right = createBT(55);
 root->left->right->left = createBT(45);
 root->left->right->right = createBT(60);

 struct node* ptr = nonRecMin(root);
 if(ptr == NULL)
    printf("No minimum value.");
 else
    printf("The minimum value is %d.", ptr->data);

 return 0;
}


