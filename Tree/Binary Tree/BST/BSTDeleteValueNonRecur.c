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

struct node* case1(struct node* root, struct node* ptr, struct node* par){
 if(root == NULL)
    root = NULL;
 else if(ptr == par->left)
    par->left = NULL;
 else
    par->right = NULL;
 free(ptr);
 return root;
};

struct node* case2(struct node* root, struct node* ptr, struct node* par){
 struct node* child;
 if(ptr->left != NULL)
   child = ptr->left;
 else if(ptr->right != NULL)
    child = ptr->right;
 if(par == NULL)
    root = child;
 else if(ptr == par->left)
    par->left = child;
 else
    par->right = child;
 return root;

};

struct node* case3(struct node* root, struct node* ptr){
 struct node* successor,*parsuccessor;
 parsuccessor = ptr;
 successor = ptr->right;

 while(successor->left != NULL){
    parsuccessor = successor;
    successor = successor->left;
 }
 ptr->data =  successor->data;
 if(successor->left == NULL && successor->right == NULL)
    root = case1(root,successor,parsuccessor);
 else
    root = case2(root,successor,parsuccessor);
 return root;
};

struct node* deleteNonRec(struct node* root, int key){
 struct node* ptr, *par;
 ptr = root;
 par = NULL;
 while(ptr != NULL){
    if(key == ptr->data)
        break;
    par = ptr;
    if(key < ptr->data)
        ptr = ptr->left;
    else
        ptr = ptr->right;
 }
 if(ptr->left != NULL && ptr->right != NULL){
    root = case3(root, ptr);
 }
 else if(ptr->left != NULL || ptr->right != NULL ){
    root = case2(root,ptr,par);
 }
 else
    root = case1(root,ptr,par);
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
 root->right->left = createBT(70);
 root->left->right->left = createBT(45);
 root->left->right->right = createBT(60);

 printf("\nBefore deletion : ");
 printBst(root);

 printf("\nAfter deletion : ");
 root = deleteNonRec(root,34);
 printBst(root);
 return 0;
}





