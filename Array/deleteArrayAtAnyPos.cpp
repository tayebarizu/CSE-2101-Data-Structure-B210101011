#include<iostream>
using namespace std;

struct ADT{
   int *arr;
   int sz;
   int len;
};

void inputArr(struct ADT var){
   int i;
   cout<<"Enter an array"<<endl;
   for(i=0;i<var.len;i++){
    cin>>var.arr[i];
   }
}
void display(ADT var){
  int i;
  for(i=0; i<var.len; i++){
    cout<<var.arr[i]<<" ";
  }
  cout<<endl;
}
int dlt(ADT *var,int pos){
   int i,res;
   res = var->arr[pos];
   for(i=pos; i<var->len; i++){
    var->arr[i]=var->arr[i+1];
   }
   var->len--;
   return res;
}

int main(){
 struct ADT arr1;
 arr1.sz = 20;
 cin>>arr1.len;

 arr1.arr = new int [arr1.sz];

 inputArr(arr1);
 display(arr1);

 cout<<dlt(&arr1,4)<<endl;
 display(arr1);
}
