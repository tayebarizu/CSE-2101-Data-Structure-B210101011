//For Undirected Graph
#include<stdio.h>
#define Max 100

//When we declare a matrix globally its all value will be zero initially.
int adj[Max][Max];

int main()
{
    int edge,vertex,v1,v2;
    printf("Enter number of vertex: ");
    scanf("%d",&vertex);
    printf("Enter number of edge: ");
    scanf("%d",&edge);

    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&v1,&v2);
        adj[v1][v2]=1;
        adj[v2][v1]=1;
    }
    for(int j=0;j<vertex;j++)
    {
        for(int k=0;k<vertex;k++)
        {
            printf("%d\t",adj[j][k]);
        }
        printf("\n");
    }


    return 0;
}
