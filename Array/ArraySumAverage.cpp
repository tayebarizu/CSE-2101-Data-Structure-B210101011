#include<iostream>
using namespace std;

struct ADT{
  int *arr;
  int sz;
  int len;
};

void inpArray(ADT var){
  int i;
  for(i=0;i<var.len;i++){
    cin>>var.arr[i];
  }
}

void display(ADT var){
 int i;
 for(i=0;i<var.len; i++){
    cout<<var.arr[i]<<" ";
 }
 cout<<endl;
}

int sum(ADT *var){
 int i;
 int sum = 0;
 for(i=0;i<var->len;i++){
   sum = sum+var->arr[i];
 }
 return sum;
}

float avrg(ADT *var){
    float avg;
    //avg = sum(&var)/var->len;
    int i;
    int sum = 0;
    for(i=0;i<var->len;i++){
    sum = sum+var->arr[i];
 }
   avg = sum/(var->len);
    return avg;
}

int main(){
  struct ADT arr1;
  arr1.sz = 20;
  cin>>arr1.len;
  arr1.arr = new int [arr1.sz];

  inpArray(arr1);
  display(arr1);

  cout<<sum(&arr1)<<endl;
  display(arr1);

  cout<<avrg(&arr1)<<endl;

  return 0;
}
