#include<iostream>
using namespace std;

void insertLastPos(int *arr, int size, int ele){
    arr[size] = ele;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int ele;
    cin>>ele;
    cout<<"Before insertion"<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertLastPos(arr,size,ele);
    cout<<"After Insertion"<<endl;
    for(int i=0; i<=size;i++){
        cout<<arr[i]<<" ";
    }
 return 0;

}
