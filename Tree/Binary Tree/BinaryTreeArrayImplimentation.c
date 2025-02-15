#include<stdio.h>
#include<stdlib.h>
#define MAX 10

char tree[MAX];

void root(char c){
 if(tree[0] != '\0'){
    printf("The root is already exits.");
 }
 else{
    tree[0] = c;
 }
}

void leftChild(char fc, int par){
 if(tree[par] == '\0'){
    printf("Can't insert %c. The parent of %c is not exists.\n", fc, fc);
 }
 else
    tree[(2*par)+1] = fc;
}

void rightChild(char rc, int par){
 if(tree[par] == '\0'){
    printf("Can't insert %c. The parent of %c is not exists.\n", rc, rc);
 }
 else
    tree[(2*par)+2] = rc;
}

void print(){
 for(int i = 0; i<MAX; i++){
    if(tree[i] == '\0'){
        printf("*");
    }
    else{
        printf("%c", tree[i]);
    }
 }
}

int main(){
 root('A');
 leftChild('B',0);
 rightChild('C',0);
 leftChild('D',1);
 rightChild('E',1);
 print();

 return 0;
}
