#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node* left;
 int data;
 struct node* right;
};

struct node* createTree(){
 int input, data;
 printf("Do you want to input a data? For yes press 1 or for no press 0 : ");
 scanf("%d",&input);
 if(!input)
    return NULL;
 else{
    struct node* newN = malloc(sizeof(struct node));
    printf("Enter a value : ");
    scanf("%d",&data);
    newN->data = data;
    printf("Left child of %d\n",newN->data);
    newN->left = createTree();
    printf("Right child of %d\n",newN->data);
    newN->right = createTree();
    return newN;
 }
}

int main(){
 struct node* root = createTree();
 printf("%d ",root->data);
 printf("%d ",root->left->data);
 printf("%d ",root->right->data);
 printf("%d ",root->left->left->data);
 return 0;
}
