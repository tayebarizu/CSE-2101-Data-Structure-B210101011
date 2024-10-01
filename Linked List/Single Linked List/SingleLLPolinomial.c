#include<stdio.h>
#include<stdlib.h>

struct node{
 float coeff;
 int expo;
 struct node* link;
};

struct node* insert(struct node* head, float cef, int ex){
  struct node* temp;
  struct node* newN = malloc(sizeof(struct node));
  newN->coeff = cef;
  newN->expo = ex;
  newN->link = NULL;

  if(head == NULL || ex > head->expo){
    newN->link = head;
    head = newN;
  }
  else{
    temp = head;
    while(temp->link != NULL && temp->link->expo >= ex)
        temp = temp->link;
    newN->link = temp->link;
    temp->link = newN;
  }
  return head;
};

struct node* create(struct node* head){
 int i, n;
 float coeff;
 int expo;
 printf("Enter the numbers of terms: ");
 scanf("%d", &n);
 for(i=0; i<n; i++){
    printf("Enter the Coefficient for %d", i+1);
    scanf("%f", &coeff);

    printf("Enter the Exponential for %d", i+1);
    scanf("%d", &expo);

    head = insert(head,coeff,expo);
 }
 return head;
};

void print(struct node* head){
 if(head == NULL)
    printf("There is no polynomial.");
 else{
    struct node* temp = head;
    while(temp != NULL){
        printf("(%.1fx^%d)", temp->coeff, temp->expo);
        temp = temp->link;
         if(temp != NULL)
    printf("+");
    else
        printf("\n");
    }
 }
}

int main(){
 struct node* head = NULL;
 printf("Enter the polynomial.\n");

 head = create(head);
 print(head);

 return 0;
}
