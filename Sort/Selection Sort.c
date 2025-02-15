#include<stdio.h>
int i,j,n,min,temp,a[100];

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
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
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


