#include<stdio.h>
#include<stdlib.h>

struct node{
  float coeff;
  int expo;
  struct node* link;
};

struct node* insert(struct node* head, float co, int ex){
  struct node* newN = malloc(sizeof(struct node));
  struct node* temp;
  newN->coeff = co;
  newN->expo = ex;
  newN->link = NULL;

  if(head == NULL || ex > head->expo){
    newN->link = head;
    head = newN;
  }
  else{
  temp = head;
  while(temp->link != NULL && temp->link->expo > ex)
    temp = temp->link;
  newN->link = temp->link;
  temp->link = newN;
  }

  return head;
};

struct node* create(struct node* head){
  int n,i,expo;
  float co;
  printf("Enter the temrs : ");
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    printf("Enter the coefficient for %d: ",i);
    scanf("%f",&co);
    printf("Enter The exponent for %d: ", i);
    scanf("%d",&expo);

    head = insert(head,co,expo);
  }
  return head;
};

void print(struct node* head){
 struct node* ptr;
 if(head == NULL)
    printf("There is no polynomial");
 else{
    ptr = head;
    while(ptr != NULL){
        printf("(%.1f^%d)",ptr->coeff, ptr->expo);
        ptr = ptr->link;
        if(ptr != NULL)
            printf("+");
        else
            printf("\n");
    }
 }
}

void polyAdd(struct node *head1, struct node* head2){
 struct node* ptr1 = head1;
 struct node* ptr2 = head2;
 struct node* head3 = NULL;

 while(ptr1 != NULL && ptr2 != NULL){
 if(ptr1->expo == ptr2->expo){
    head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
    ptr1 = ptr1->link;
    ptr2 = ptr2->link;
 }
 else if(ptr1->expo > ptr2->expo){
    head3 = insert(head3, ptr1->coeff, ptr1->expo);
    ptr1 = ptr1->link;
 }
 else if(ptr2->expo > ptr1->expo){
    head3 = insert(head3, ptr2->coeff, ptr2->expo);
    ptr2 = ptr2->link;
  }
 }

 while(ptr1 != NULL){
    head3 = insert(head3, ptr1->coeff, ptr1->expo);
    ptr1 = ptr1->link;
 }
 while(ptr2 != NULL){
    head3 = insert(head3, ptr2->coeff, ptr2->expo);
    ptr2 = ptr2->link;
 }

 printf("The polynomial after addition : ");
 print(head3);
}

int main(){
 struct node* head1 = NULL;
 struct node* head2 = NULL;
 printf("Enter the First polynomial: \n");
 head1 = create(head1);
 print(head1);

 printf("Enter the Second polynomial: \n");
 head2 = create(head2);
 print(head2);

 polyAdd(head1, head2);

 return 0;
}
