#include<iostream>
using namespace std;

bool sorted(int *arr, int sz){
  if(sz==0||sz==1){
    return true;
  }
  else if(arr[0]>arr[1]){
    return false;
  }
  else{
    int ans = sorted(arr+1, sz-1);
    return ans;
  }
}


int main(){
  int *arr;
  int len;
  cin>>len;
  for(int i =0; i<len; i++){
    cin>>arr[i];
  }

  for(int i = 0; i<len; i++);

  int ans = sorted(arr,len);
  if(ans){
    cout<<"Array is Sorted"<<endl;
  }
  else{
    cout<<"Array is not Sorted"<<endl;
  }
  return 0;
}
