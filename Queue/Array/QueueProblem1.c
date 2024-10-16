//Write a program to impliment a queue using two stacks
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

void push1(int d){
 top1++;
 stack1[top1] = d;
}

void push2(int d){
 top2++;
 stack2[top2] = d;
}

int pop1(){
 int val = stack1[top1];
 top1--;
 return val;
}

int pop2(){
 int val = stack2[top2];
 top2--;
 return val;
}

void enQ(int d){
 if(top1 == MAX-1){
     printf("Queue Overflow!");
     exit(1);
 }
 push1(d);
}

int deQ(){
 int temp;
 if(top2 == -1){
    if(top1 == -1){
        printf("Queue underflow!\n");
        exit(1);
    }
    while(top1 != -1){
        temp = pop1();
        push2(temp);
    }
 }
 return pop2();
}

int peek(){
 if(top1 == -1 && top2 == -1){
    printf("Queue underflow!\n");
    exit(1);
 }
 if(top2 == -1)
    return stack1[0];
 else
    return stack2[top2];
}

void print(){
  if(top1 == -1 && top2 == -1){
    printf("Queue underflow!\n");
    exit(1);
 }

 for(int i = 0; i<=top1; i++){
    printf("%d ",stack1[i]);
 }

 for(int i = top2; i>=0; i--){
    printf("%d ",stack2[i]);
 }
 printf("\n");
}

int main(){
 int data,choice;
 while(1){
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Print the first element\n");
    printf("4.Print all the element\n");
    printf("5.Quit\n");

    printf("Enter a choice : ");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    enQ(data);
    printf("The element inserted successfully.\n");
    break;
case 2:
    data = deQ();
    printf("Deleted element is : %d\n",data);
    break;
case 3:
    printf("The first element is : %d\n",peek());
    break;
case 4:
    printf("Queue : ");
    print();
    break;
case 5:
    exit(1);
default:
    printf("Wrong choice.\n");
    }
}
return 0;
}
