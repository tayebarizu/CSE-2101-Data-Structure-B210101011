#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
 int height;
};

struct node* createNode(int d){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = d;
 newN->right = NULL;
 newN->height = 0;

 return newN;
};

int height(struct node* n){
 if(n== NULL)
    return -1;
 return n->height;
}

int max(int x,int y){
 return x>y?x:y;
}

int getBalanceF(struct node* n){
 if(n == NULL)
    return 0;
 else
    return ((height(n->left)+1)-(height(n->right)+1));
}

struct node* leftRotation(struct node* A){
 struct node* B = A->right;
 A->right = B->left;
 B->left = A;

 A->height = 1+max(height(A->left),height(A->right));
 B->height = 1+max(height(B->left),height(B->right));

 return B;
};

struct node* rightRotation(struct node* B){
 struct node* A = B->left;
 B->left = A->right;
 A->right = B;

 B->height = 1+max(height(B->left),height(B->right));
 A->height = 1+max(height(A->left),height(A->right));

 return A;
};

struct node* balance(struct node* n, int BF, int key){
 if(BF>1){
    if(key>n->left->data)
        n->left = leftRotation(n->left);
    return rightRotation(n);
 }
 if(BF<-1){
    if(key<n->right->data)
        n->right = rightRotation(n->right);
    return leftRotation(n);
 }
 return n;
};

struct node* insert(struct node* currNode, int key){
 if(currNode == NULL)
    return (createNode(key));
 if(key<currNode->data)
    currNode->left = insert(currNode->left,key);
 else if(key>currNode->data)
    currNode->right = insert(currNode->right,key);
 else
    return currNode;
 currNode->height = 1+max(height(currNode->left),height(currNode->right));
 int balanceF = getBalanceF(currNode);
 return balance(currNode,balanceF,key);
};

void print(struct node* root){
 if(root == NULL)
    return;
 printf("%d ",root->data);
 print(root->left);
 print(root->right);
}

int main(){
 struct node* root = NULL;
 root = insert(root,25);
 root = insert(root,10);
 root = insert(root,80);
 root = insert(root,63);
 root = insert(root,65);

 print(root);

 return 0;
}
