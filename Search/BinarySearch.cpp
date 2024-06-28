          #include<iostream>
using namespace std;
int binarySearch(int arr[],int size, int key){
 int start = 0, end = size-1;
 int mid = start+(end-start)/2;
 while(start<=end){
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]<key){
        start = mid+1;
    }
    else{
        end = mid-1;
    }
    mid = start+(end-start)/2;
 }
 return -1;
}
int main(){
 int even[6]={6,8,2,4,10,12};
 int odd[5]={1,3,7,5,9};
 int evenIndex = binarySearch(even,6,12);
 cout<<"Even Index is "<<evenIndex<<endl;
 int oddIndex = binarySearch(odd,5,9);
 cout<<"Odd Index is "<<oddIndex<<endl;
}
