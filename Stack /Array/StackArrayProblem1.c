//stack_arr[0] as the top.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

int isFull(){
 if(first == MAX-1)
   return 1;
   else
    return 0;
}

int isEmpty(){
 if(first == -1)
   return 1;
   else
    return 0;
}

void push(int d){
  if(isFull()){
    printf("Stack is overflow!");
    exit(1);
  }

 first += 1;

 for(int i=first;i>0;i--)
    stack_arr[i] = stack_arr[i-1];
    stack_arr[0] = d;
}

int pop(){
 int i,val;
 if(isEmpty()){
    printf("Stack is underflow!");
    exit(1);
  }

 val = stack_arr[0];
 for(i=0;i<=first;i++)
    stack_arr[i] = stack_arr[i+1];
  first -= 1;
  return val;
}

int peek(){
 if(isEmpty()){
    printf("Stack is underflow!");
    exit(1);
  }
  return stack_arr[0];
}

void print(){
 if(first == -1){
    printf("Stack is underflow.");
    return;
 }
 for(int i=0; i<=first; i++){
    printf("%d ",stack_arr[i]);
 }
}

int main(){
 int data,choice;

 while(1){
    printf("\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Print the top element\n");
    printf("4.Print all the element\n");
    printf("5.Quit\n");

    printf("Enter a choice: ");
    scanf("%d",&choice);

    switch(choice){
 case 1:
    printf("Enter the element to be pushed: ");
    scanf("%d",&data);
    push(data);
    break;
 case 2:
    data = pop();
    printf("Deleted element is: %d\n", data);
    break;
 case 3:
    printf("The topmost element is: %d\n",peek());
    break;
 case 4:
    print();
    break;
 case 5:
    exit(1);
 default:
    printf("Wrong choice is entred!\n");
    }
 }

 return 0;
}
