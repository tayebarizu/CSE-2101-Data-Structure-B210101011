#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

int isEmpty(){
 if(top == -1)
    return 1;
 else
    return 0;
}

void push(char c){
 if(top == MAX-1)
    return;
 top++;
 stack[top] = c;
}

char pop(){
 if(isEmpty())
    exit(1);
 char temp = stack[top];
 top--;
 return temp;
}

int match_char(char a, char b){
 if(a =='[' && b == ']' )
    return 1;
 if(a =='{' && b == '}' )
    return 1;
 if(a =='(' && b == ')' )
    return 1;
 return 0;
}

int checkBalance(char* s){
 char temp;
 int i;
 for(i = 0; i<strlen(s); i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        push(s[i]);

        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(isEmpty()){
            printf("Right brackets are more than left brackets.\n");
            return 0;
        }
        else{
            temp = pop();
            if(!match_char(temp,s[i])){
                printf("Mismatched brackets.\n");
                return 0;
            }
        }
    }
 }
 if(isEmpty()){
    printf("The expression is balanced.\n");
    return 1;
 }

 else{
    printf("Left brackets are more than the rights.\n");
    return 0;
 }

}

int main(){
 char exp[MAX];
 printf("Give the algabric expression: ");
 gets(exp);

 int balance = checkBalance(exp);

 if(balance == 1){
    printf("The expression is valid.\n");
 }
 else
    printf("The expression is not valid.\n");

 return 0;
}
