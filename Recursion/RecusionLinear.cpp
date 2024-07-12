#include<iostream>
using namespace std;
bool linearSrch(int *arr, int sz, int k){
  if(sz==0){
    return false;
  }

  if(arr[0]==k){
    return true;
  }
  else{
    int res = linearSrch(arr+1, sz-1, k);
    return res;
  }
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

  bool ans = linearSrch(arr,len,key);
  if(ans){
    cout<<"Key is found"<<endl;
  }
  else{
    cout<<"Key is not found"<<endl;
  }
  return 0;
}
