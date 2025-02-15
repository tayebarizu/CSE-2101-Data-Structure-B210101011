#include<stdio.h>
int i,j,n,key,a[100];

void insert(int n)
{
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int n,int a[100])
{
    printf("Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}
void sort(int n,int a[100])
{
    for(i=1; i<n; i++)
    {
        key=a[i];
        j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    printf("Enter array size:");
    scanf("%d",&n);
    printf("\nEnter array:");
    insert(n);
    display(n,a);
    sort(n,a);
    printf("\nAfter sorting ");
    display(n,a);

    getch();
}

