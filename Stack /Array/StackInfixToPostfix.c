#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;
char infix[MAX],postfix[MAX];

int isEmpty(){
 if(top == -1)
    return 1;
 else
    return 0;
}

int isFull(){
 if(top == MAX-1){
    return 1;
 }
 else
    return 0;
}

void push(char s){
 if(isFull()){
    exit(1);
 }
 top++;
 stack[top] = s;
}

char pop(){
 if(isEmpty()){
    exit(1);
 }
 char temp = stack[top];
 top--;
 return temp;
}

int precedence(char c){
 switch(c){
  case '^':
      return 3;
   case '*':
   case '/':
      return 2;
   case '+':
   case '-':
      return 1;
   default:
    return 0;
 }
}


int space(char c){
 if(c ==' ' || c =='\t')
    return 1;
 else
    return 0;
}

void inToPost(){
 int i,j=0;
 char symbol,next;
 for(i=0; i<strlen(infix);i++){
    symbol = infix[i];
    if(!space(symbol)){
    switch(symbol){
 case '(':
    push(symbol);
    break;
 case ')':
    while((next = pop())!='(')
    postfix[j++] = next;
    break;
 case '+':
 case '-':
 case '*':
 case '/':
 case '^':
    while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
        postfix[j++] = pop();
    push(symbol);
    break;
 default:
    postfix[j++] = symbol;
    }
  }
 }
 while(!isEmpty())
    postfix[j++] = pop();
 postfix[j] = '\0';
}

void print(){
 int i = 0;
 printf("The equivalent postfix expression is: ");
 while(postfix[i]){
    printf("%c ",postfix[i++]);
 }
 printf("\n");
}

int main(){
 printf("Enter the infix expression:");
 gets(infix);

 inToPost();
 print();

 return 0;
}
