#include<iostream>
using namespace std;

void bubbleSort(int *arr, int size){
    for(int i=0; i<size; i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int arr[5] = {4,2,8,6,3};
    cout<<"Before sort"<<endl;
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr,5);

    cout<<"After sort"<<endl;
     for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
}
