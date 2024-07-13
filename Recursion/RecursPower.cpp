#include<iostream>
using namespace std;

int power(int x, int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    if(n%2==0){
        return power(x,n/2)*power(x,n/2);
    }
    else{
        return x*power(x,n/2)*power(x,n/2);
    }
}

int main(){
 int x,n;
 cin>>x>>n;

 int res = power(x,n);

 cout<<"Result is : "<<res<<endl;

 return 0;
}
