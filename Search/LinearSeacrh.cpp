#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
 for(int i=0;i<size;i++){
    if(arr[i]==key){
        return 1;
    }
 }
    return 0;
}
int main(){
 int arr[10]={5,-2,10,1,11,6,7,12,4,43};
 int key;
 cin>>key;
 bool found=search(arr,10,key);
 if(found){
    cout<<"The element is found"<<endl;
 }
 else{
    cout<<"The element is not found"<<endl;
 }
}
