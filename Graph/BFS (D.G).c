#include<stdio.h>
#define Max 100

int adj[Max][Max], visit[Max],vertex,edge;

void BFS(int vertices)
{
    int i;
    printf("%d ",vertices);
    visit[vertices]=1;
    for(i=0;i<vertex;i++)
    {
        if(visit[i]!=1 && adj[vertices][i]==1)
        {
            BFS(i);
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&vertex);
    printf("Enter number of edges: ");
    scanf("%d",&edge);
    printf("Enter graph edges:\n");
    for(int i=0; i<edge; i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        adj[v1][v2]=1;
    }
    printf("\n");
    for(int j=0; j<vertex; j++)
    {
        for(int k=0; k<vertex; k++)
        {
            printf("%d\t",adj[j][k]);
        }
        printf("\n");
    }

    printf("\nTotal vertices in graph: ");

    //Starting point of BFS
    BFS(0);//Call BFS function using root vertices

    printf("\n");

    return 0;
}
