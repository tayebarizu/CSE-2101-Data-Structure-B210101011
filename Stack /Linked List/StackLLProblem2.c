//palindrome

#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
}*top = NULL;

int isEmpty(){
 if(top == NULL)
   return 1;
 else
   return 0;
}

void push(int d){
 struct node* newN = malloc(sizeof(struct node));

 if(newN == NULL){
    printf("THE STACK IS OVERFLOW.");
    exit(1);
 }

 newN->data = d;
 newN->link = NULL;

 newN->link = top;
 top = newN;
}

int pop(){
 int val;
 struct node* temp;

 if(isEmpty()){
    printf("The stack is underflow.");
    exit(1);
 }

 temp = top;
 val = temp->data;
 top = top->link;
 free(temp);
 temp = NULL;
 return val;
}

void isPalindrome(char* s){
 int i = 0;
 while(s[i] != 'X'){
    push(s[i]);
    i++;
 }
 i++;

 while(s[i]){
    if(isEmpty() || pop() != s[i]){
        printf("Not palindrome.");
        exit(1);
    }
    i++;
 }
 if(isEmpty())
    printf("Palindrome.");
 else
   printf("Not palindrome.");
}

int main(){
 char s[100];
 printf("Enter the string: ");
 scanf("%s",s);

 isPalindrome(s);

 return 0;
}
