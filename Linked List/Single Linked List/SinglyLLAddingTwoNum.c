#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

struct node* reverse(struct node* head){
 struct node* cur = NULL;
 struct node* next = head->link;
 head->link = NULL;

 while(next != NULL){
    cur = next;
    next = next->link;
    cur->link = head;
    head = cur;
 }

 return head;
};

struct node* add_node(struct node* head,int d){
  struct node* newN = malloc(sizeof(struct node));

  newN->data = d;
  newN->link = NULL;

  newN->link = head;
  head = newN;

  return head;
};

struct node* create(struct node* head,int n){
  if(n == 0)
    printf("There is no number.");
  else{
    while(n != 0){
        head = add_node(head, n%10);
        n = n/10;
    }
  }
  return head;
};

struct node* addNum(struct node* head1, struct node* head2){
 if(head1->data == 0)
    return head2;
 if(head2 == 0)
    return head1;
 struct node* ptr1 = head1;
 struct node* ptr2 = head2;
 struct node* head3 = NULL;
 int carry = 0, sum;

 while(ptr1 || ptr2){
    sum = 0;
    if(ptr1)
        sum += ptr1->data;
    if(ptr2)
        sum += ptr2->data;
    sum += carry;

    carry = sum/10;
    sum = sum%10;

    head3 = add_node(head3,sum);

    if(ptr1)
        ptr1 = ptr1->link;
     if(ptr2)
        ptr2 = ptr2->link;
 }
 if(carry)
    head3 = add_node(head3,carry);

 return head3;
};

void print(struct node* head){
 if(head == NULL)
    printf("There is node!!");
 else{
    struct node* temp = head;
    while(temp->link != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d",temp->data);
 }
}

void backNum(struct node* head){
 struct node* temp = head;
 printf("\nResult : ");
 while(temp){
    printf("%d",temp->data);
    temp = temp->link;
 }
}

int main(){
 int a,b;
 printf("Enter the Numbers: ");
 scanf("%d %d", &a,&b);

 printf("Presentation of first number as linked list:\n ");
 struct node* head1 = NULL;
 head1 = create(head1,a);
 print(head1);

 printf("\nPresentation of second number as linked list:\n ");
 struct node* head2 = NULL;
 head2 = create(head2,b);
 print(head2);

 head1 = reverse(head1);
 head2 = reverse(head2);

 printf("\nAfter reverse the link list: \n");
 print(head1);
 printf("\n");
 print(head2);

 struct node* head3 = NULL;
 head3 = addNum(head1, head2);
 printf("\nAfter addition: \n");
 print(head3);

 backNum(head3);

 return 0;
}
