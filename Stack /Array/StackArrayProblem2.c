//Write a program to print all the prime factors of a number in descending order using stack.
#include<stdio.h>
#include<stdlib.h>
#define MAX 40

int stack[MAX];
int top = -1;
int isFULL(){
 if(top == MAX-1)
   return 1;
 else
    return 0;
}

int isEmpty(){
 if(top == -1)
   return 1;
 else
    return 0;
}

void push(int d){
 if(isFULL()){
        printf("The stack is overflow!");
        return;
     }
     top++;
     stack[top] = d;
 }

int pop(){
  if(isEmpty()){
    printf("The stack is underflow!");
    exit(1);
  }
  int val;
  val = stack[top];
  top--;
  return val;
}

void prime_fact(int num){
 int i = 2;
 while(num!=1){
    while(num%i == 0){
        push(i);
        num = num/i;
    }
    i++;
 }
 printf("The prime factors of the number in descending order is: \n");
 while(top != -1){
 printf("%d ",pop());
 }
}

int main(){
    int n;
 printf("Enter a positive Number: ");
 scanf("%d",&n);
 prime_fact(n);
}
