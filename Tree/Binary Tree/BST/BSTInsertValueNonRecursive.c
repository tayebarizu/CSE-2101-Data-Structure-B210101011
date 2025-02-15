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

struct node* insert_nonRec(struct node* root, int key){
 struct node* ptr, *temp, *par;
 ptr = root;
 par = NULL;
 while(ptr != NULL){
    par = ptr;
    if(key<ptr->data)
        ptr = ptr->left;
    else if(key>ptr->data)
        ptr = ptr->right;
    else{
        printf("Duplicate key!\n");
        return root;
    }
 }
 temp = createBT(key);
 if(par == NULL)
    root = temp;
 else if(key < par->data)
    par->left = temp;
 else
    par->right = temp;
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

 root = insert_nonRec(root,30);
 printBst(root);

 return 0;
}



