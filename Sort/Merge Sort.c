#include<stdio.h>
#include<conio.h>
#define MAX 100

int arr[MAX],copy[MAX];

int mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int merge(int arr[],int low,int mid,int high)
{
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;

    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            copy[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            copy[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=high)
        {
            copy[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            copy[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=low; k<=high; k++)
    {
        arr[k] = copy[k];
    }
}

int display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

}

int array(int n)
{
    int i;
    printf("Enter array element: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

}

int main()
{
    int i,n;
    printf("Enter array size:");
    scanf("%d",&n);
    array(n);
    printf("\nArray: ");
    display(arr,n);
    mergesort(arr,0,n-1);
    printf("\nArray after sorting: ");
    display(arr,n);

    getch();
}
