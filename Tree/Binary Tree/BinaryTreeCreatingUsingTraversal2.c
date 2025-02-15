#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createNode(char data){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = data;
 newN->right = NULL;
 return newN;
};

int searchIndex(char inArr[], int data, int inStart, int inEnd){
 int i;
 for(i = inStart; i<=inEnd; i++){
    if(inArr[i]==data)
        return i;
 }
}

struct node* constructBT(char postArr[],char inArr[],int inStart, int inEnd,int* post){
 if(inStart>inEnd)
    return NULL;
 struct node* temp = createNode(postArr[*post]);
 (*post)--;
 if(inStart == inEnd)
    return temp;
 int inIndex = searchIndex(inArr,temp->data,inStart,inEnd);
 temp->right = constructBT(postArr,inArr,inIndex+1,inEnd,post);
 temp->left = constructBT(postArr,inArr,inStart,inIndex-1,post);
 return temp;
};

struct node* helper(char postArr[],char inArr[], int n){
 int postIndex = n-1;
 return constructBT(postArr,inArr,0,n-1,&postIndex);
};

void printPost(struct node* root){
 if(root == NULL)
    return;
  printPost(root->left);
  printPost(root->right);
  printf("%c ", root->data);
}

int main(){
 char postArr[] = {'D','E','B','F','C','A'};
 char inArr[] = {'D','B','E','A','F','C'};
 int length = (sizeof(inArr))/(sizeof(inArr[0]));
 struct node* root = helper(postArr,inArr,length);
 printPost(root);
 return 0;
}
