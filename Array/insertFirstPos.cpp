#include<iostream>
using namespace std;
void InsertFirstPos(int *arr, int size, int ele){
    for(int i=size-1;i>=0; i--){
        arr[i+1]=arr[i];
    }
    arr[0]=ele;
}
int main(){
int size;
cout<<"Enter a size"<<endl;
cin>>size;
int arr[size];
for(int i=0;i<size;i++){
    cin>>arr[i];
}
cout<<"Before Insertion: "<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
int ele;
cout<<"Enter a element: "<<endl;
cin>>ele;
InsertFirstPos(arr,size,ele);
cout<<"After Insertion"<<endl;
  for(int i=0;i<=size;i++){
    cout<<arr[i]<<" ";
  }
return 0;
}
