#include<iostream>
using namespace std;

int getSum(int *arr, int sz){
 if(sz==0){
    return 0;
 }
 else if(sz==1){
    return arr[0];
 }
 else{
    int ans = getSum(arr+1, sz-1);
    int sum = arr[0]+ans;
    return sum;
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

   int res = getSum(arr,len);
  cout<<"Sum is : " <<res<< endl;

  return 0;
}
