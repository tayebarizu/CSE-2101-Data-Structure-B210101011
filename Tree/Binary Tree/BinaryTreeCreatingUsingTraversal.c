//preOrder and inorder
#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 char data;
 struct node* right;
};

int searchIndex(char inArr[],char data,int startIn,int EndIn){
 int i;
 for(i = startIn; i<=EndIn; i++){
    if(inArr[i] == data)
        return i;
 }
}

struct node* createNode(char data){
 struct node* newN = malloc(sizeof(struct node));
 newN->left = NULL;
 newN->data = data;
 newN->right = NULL;
 return newN;
};

struct node* constructBT(char preArr[], char inArr[], int startIn, int endIn){
 static int preIndex = 0;
 if(startIn>endIn)
    return NULL;
 struct node* temp = createNode(preArr[preIndex]);
 preIndex++;
 if(startIn == endIn)
    return temp;
 int inIndex = searchIndex(inArr,temp->data, startIn,endIn);
 temp->left = constructBT(preArr,inArr,startIn,inIndex-1);
 temp->right = constructBT(preArr,inArr,inIndex+1,endIn);
 return temp;
};

void printpre(struct node* root){
 if(root == NULL){
   return;
 }
 printf("%c ",root->data);
 printpre(root->left);
 printpre(root->right);
}

int main(){
 char preArr[] = {'A','B','D','E','C','F'};
 char inArr[] = {'D','B','E','A','F','C'};
 int length = (sizeof(inArr))/(sizeof(inArr[0]));
 struct node* root = constructBT(preArr,inArr,0,length-1);
 printpre(root);

 return 0;
}
