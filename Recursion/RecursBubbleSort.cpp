#include<iostream>
using namespace std;

void inpArr(int *arr, int sz){
 for(int i = 0; i<sz; i++){
    cin>>arr[i];
 }
}

void display(int *arr, int sz){
 for(int i = 0; i<sz; i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
}

void bubbleSort(int *arr, int sz){
   if(sz==1||sz==0){
    return;
   }

   for(int i = 0; i<sz-1; i++){
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
   }
   bubbleSort(arr,sz-1);
}
int main(){
  int *arr;
  int sz = 20;
  int len;
  cin>>len;

  inpArr(arr,len);
  display(arr,len);

  bubbleSort(arr,len);
  display(arr,len);
}
