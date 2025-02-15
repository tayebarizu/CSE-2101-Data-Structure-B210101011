#include<stdio.h>
#include<stdlib.h>

struct node{
struct node* left;
int data;
struct node* right;
int height;
};

struct node* createNode(int d){
 struct node* temp = malloc(sizeof(struct node));
 temp->left = NULL;
 temp->data = d;
 temp->right = NULL;
 temp->height = 0;
 return temp;
};

int height(struct node* n){
 if(n==NULL)
    return -1;
 return n->height;
}

int max(int x, int y){
 return (x>y)? x:y;
}

struct node* leftRotate(struct node* A){
 struct node* B = A->right;
 A->right = B->left;
 B->left = A;

 A->height = 1+max(height(A->left),height(A->right));
 B->height = 1+max(height(B->left),height(B->right));
 return B;
};

struct node* rightRotate(struct node* B){
 struct node* A = B->left;
 B->left = A->right;
 A->right = B;

 B->height = 1+max(height(B->left),height(B->right));
 A->height = 1+max(height(A->left),height(A->right));
 return A;
};

struct node* getSuccessor(struct node* temp){
 while(temp->left != NULL)
    temp = temp->left;
 return temp;
};


int getBalanceF(struct node* n){
 if(n == NULL)
    return 0;
 return ((height(n->left)+1)-(height(n->right)+1));
}

struct node* deleteNode(struct node* currNode,int key){
 if(currNode == NULL)
    return currNode;
 if(key<currNode->data)
    currNode->left = deleteNode(currNode->left, key);
 else if(key>currNode->data)
    currNode->right = deleteNode(currNode->right, key);
 else{
    if(currNode->left == NULL || currNode->right == NULL){
        struct node* temp = NULL;
        if(currNode->left != NULL)
           temp = currNode->left;
        else if(currNode->right != NULL)
            temp = currNode->right;
        if(temp == NULL){
            temp = currNode;
            currNode = NULL;
        }
        else
            *currNode = *temp;
        free(temp);
        }
    else{
            struct node* temp = getSuccessor(currNode->right);
            currNode->data = temp->data;
            currNode->right = deleteNode(currNode->right,temp->data);
        }
    }
    if(currNode == NULL)
    return currNode;

    currNode->height = 1 + max(height(currNode->left),height(currNode->right));
    int balance = getBalanceF(currNode);
    if(balance > 1){
        if(getBalanceF(currNode->left)<0)
            currNode->left = leftRotate(currNode->left);
        return rightRotate(currNode);
    }
     if(balance < -1){
        if(getBalanceF(currNode->right)>0)
            currNode->right = rightRotate(currNode->right);
        return leftRotate(currNode);
    }

    return currNode;
 };

 void printpre(struct node* root){
  if(root == NULL)
    return;
  printf("%d ",root->data);
  printpre(root->left);
  printpre(root->right);
 }

 int main(){
  struct node* root = NULL;
  root = createNode(56);
  root->left = createNode(45);
  root->left->left = createNode(30);
  root->left->right = createNode(50);
  root->left->left->left = createNode(7);
  root->left->left->right = createNode(35);
  root->right = createNode(80);
  root->right->right = createNode(90);

  printf("Before Deletion \n");
  printpre(root);

  printf("\nAfter Deletion \n");
  root = deleteNode(root,45);
  printpre(root);

  return 0;
 }
