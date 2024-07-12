#include<iostream>
using namespace std;

bool binarySrch(int *arr, int s, int e, int key){
   if(s>e){
    return false;
   }
   int mid = s+(e-s)/2;
   if(arr[mid]==key){
    return true;
   }
   if(arr[mid]<key){
    return binarySrch(arr,mid+1,e,key);
   }
   else binarySrch(arr,s,mid-1,key);
}


int main(){
  int *arr;
  int len;
  cin>>len;
  for(int i =0; i<len; i++){
    cin>>arr[i];
  }

  for(int i = 0; i<len; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  int key;
  cout<<"Enter a key"<<endl;
  cin>>key;

  int res;
  res = binarySrch(arr,0,len-1,key);
  if(res){
        cout<<"Key is found" <<endl;
  }
  else{
    cout<<"Key is not found" <<endl;
    }
    return 0;
}
