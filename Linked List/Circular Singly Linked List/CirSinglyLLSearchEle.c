#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* next;
};

struct node* addToEmpty(int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->data = d;
  temp->next = temp;
  return temp;
};

struct node* add_end(struct node* tail, int d){
  struct node* temp = malloc(sizeof(struct node));
  temp->data = d;
  temp->next = NULL;

  temp->next = tail->next;
  tail->next = temp;
  tail = tail->next;

  return tail;
};

int searchEle(struct node* tail, int ele){
 struct node* temp = tail->next;
 int index = 0;
 if(tail==NULL)
    return -2;
 do{
    if(temp->data == ele)
        return index;
        temp = temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
}

int main(){
struct node* tail = malloc(sizeof(struct node));
tail = addToEmpty(34);
tail = add_end(tail,45);
tail = add_end(tail,66);
tail = add_end(tail,6);

int ele;
printf("Enter the Element: ");
scanf("%d", &ele);

int index = searchEle(tail,ele);
if(index == -1)
    printf("The element is not found.");
else if(index == -2)
    printf("The list is empty!!");
else
    printf("The %d is found at index %d", ele, index);

    return 0;

}
