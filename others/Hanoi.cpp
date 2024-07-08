#include<iostream>
using namespace std;

void hanoi(int disk, char source, char mid, char des){
 if(disk>0){
    hanoi(disk-1, source,des,mid);
    cout<<disk<<" "<<source<<" To "<< des<<endl;
    hanoi(disk-1,mid,source, des);
 }
}
int main(){
 int disk;
 char s,m,d;
 cin>>disk;
 hanoi(3,'s','m','d');
}
