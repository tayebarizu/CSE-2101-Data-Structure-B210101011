#include<stdio.h>
#include<conio.h>
#define MAX 100

int pivot,arr[MAX];

int quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int j = partition(arr,low,high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

int partition(int arr[],int low,int high)
{
    pivot = arr[low];
    int i,j,temp;
    i = low;
    j = high;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

int array(int n)
{
    int i;
    printf("Enter array element: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

}
int display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
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
    quicksort(arr,0,n-1);
    printf("\nArray after sorting: ");
    display(arr,n);

    getch();
}
