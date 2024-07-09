#include<iostream>
using namespace std;
struct ADT
{
    int *arr;
    int sz;
    int len;
};
void display(struct ADT var)
{
    int i;
    for(i=0; i<var.len; i++)
    {
        cout<<var.arr[i]<<" ";
    }
    cout<<endl;
}
void insrtAtAnyPos(struct ADT *var, int val,int pos)
{
    int i;
    for(i=var->len; i>pos; i--)
    {
        var->arr[i]=var->arr[i-1];
    }
    var->arr[pos]=val;
    var->len++;
}
int main()
{
    struct ADT arr1;
    int i,ele;
    arr1.sz = 20;
    cin>>arr1.len;
    arr1.arr = new int [arr1.sz];
    cout<<"Enter an array: "<<endl;
    for(i=0; i<arr1.len; i++)
    {
        cin>>arr1.arr[i];
    }

    display(arr1);

    cout<<"Enter an element"<<endl;
    cin>>ele;

    insrtAtAnyPos(&arr1,ele,3);
    display(arr1);
}
