#include<stdio.h>
#define Max 100

int adj[Max][Max], visit[Max],vertex,edge;

int array[Max];

static int k=0,count=0;

void DFS(int vertices)
{
    int c=0;
    printf("%d ",vertices);
    count++;
    visit[vertices]=1;
    for(int i=0; i<vertex; i++)
    {
        if(visit[i]!=1 && adj[vertices][i]==1)
        {
            array[++k]=i;
            c=1;
        }
        if(count==vertex)
        {
            printf("\n\n");
            exit(0);
        }
    }
    if(c==1)
    {
        DFS(array[k]);
    }
    else
    {
        k--;
        DFS(array[k]);
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
        adj[v2][v1]=1;
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

    //Starting point of DFS
    DFS(0);//Call DFS function using root vertices

    return 0;
}


