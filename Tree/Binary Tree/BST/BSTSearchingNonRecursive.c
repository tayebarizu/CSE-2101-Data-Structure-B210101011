//binary searching

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

struct node* searchNonRec(struct node* root, int key){
 if(root == NULL)
    return NULL;
 while(root != NULL){
    if(key < root->data)
        root = root->left;
    else if(key > root->data)
        root = root->right;
    else
        return root;
 }
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

 struct node* ptr = searchNonRec(root,45);
 if(ptr == NULL)
    printf("The key is not found.");
 else
    printf("The key %d is found.", ptr->data);

 return 0;
}

