#include<stdio.h>
#include<conio.h>
#define Max 100

int arr[100],output[100];

int radixsort(int n,int max)
{
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        countsort(n,max,pos);
    }
}

int countsort(int n,int max,int pos)
{
    int count[10];
    for(int i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    for(int j=1;j<10;j++)
    {
        count[j]=count[j]+count[j-1];
    }
    for(int k=n-1;k>=0;k--)
    {
        output[count[(arr[k]/pos)%10]-1]=arr[k];
        count[(arr[k]/pos)%10]--;
    }
    for(int l=0;l<n;l++)
    {
        arr[l]=output[l];
    }
}

int getMax(int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("\n\nMax= %d\n",max);
    return max;
}

int insert(int n)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}
int display(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n,max;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("\nEnter array:");
    insert(n);
    printf("Array: ");
    display(n);

    max=getMax(n);

    radixsort(n,max);

    printf("\nArray after sorting: ");
    display(n);

    getch();
}

