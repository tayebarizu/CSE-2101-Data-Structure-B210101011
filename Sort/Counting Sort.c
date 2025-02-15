#include<stdio.h>
#include<conio.h>

int i,j,n,max,p,a[100];

int insert(int n)
{
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
int display(int n,int a[])
{
    printf("Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}
int high(int n,int a[])
{
    max=a[0];
    for(i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("\nMax %d",max);
    return max;
}
int sort(int max,int n,int a[])
{
    int count[max+1];

    int out[n];

    for(i=0; i<=max; i++)
    {
        count[i]=0;
    }
    for(i=0; i<n; i++)
    {
        count[a[i]]++;
    }
    for(i=1; i<=max; i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        out[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    printf("\nAfter sorting Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ",out[i]);
    }
}

int main()
{
    printf("Enter array size:");
    scanf("%d",&n);
    printf("\nEnter array:");
    insert(n);
    display(n,a);
    p=high(n,a);
    sort(p,n,a);

    getch();
}
