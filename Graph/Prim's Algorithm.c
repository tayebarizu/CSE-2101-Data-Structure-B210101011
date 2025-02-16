#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define Max 100

void primMST(int vertex,int graph[Max][Max])
{
    //Array to store constructed MST
    int parent[vertex];
    //Key values used to pick minimum weight edge for every vertices
    int key[vertex];
    //To represent set of vertices included in MST
    bool mstSet[vertex];
    for(int i=0; i<vertex; i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }

    /*Always include first 1st vertex in MST.
    Make key 0 so that this vertex is picked as first vertex.*/
    key[0]=0;

    for(int count=0; count<vertex-1; count++)
    {
        int u=minKey(vertex,key,mstSet);
        mstSet[u]=true;

        for(int V=0; V<vertex; V++)
        {
            if(graph[u][V]!=0 && mstSet[V]==false && graph[u][V]<key[V])
            {
                parent[V]=u;
                key[V]=graph[u][V];
            }
        }
    }

    printMST(vertex,parent,graph);

}

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int vertex,int key[],bool mstSet[]) //Check the next parent
{
    int min=INT_MAX;
    int min_index;
    for(int v=0; v<vertex; v++)
    {
        if(mstSet[v]==false && key[v]<min)
        {
            min=key[v];
            min_index=v;
        }
    }

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int V,int parent[],int graph[Max][Max])
{
    int cost=0;
    printf("\nEdge\tWeight\n\n");
    for(int i=1; i<V; i++)
    {
        cost=cost+graph[i][parent[i]];
        printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
    }
    printf("\nTotal Cost: %d\n",cost);
}

int main()
{
    int vertex;
    printf("Enter the number of vertex: ");
    scanf("%d",&vertex);
    int graph[Max][Max]= { { 0, 8, 0, 7, 2, 0},
        { 8, 0, 3, 0, 0, 0 },
        { 0, 3, 0, 9, 0, 5},
        { 7, 0, 9, 0, 1, 0},
        { 2, 0, 0, 1, 0, 10},
        { 0, 0, 5, 0, 10, 0}
    };

    /*int graph[Max][Max]={{0,2,0,0,0,4},
        {2,0,8,0,0,3},
        {0,8,0,6,1,0},
        {0,0,6,0,12,0},
        {0,0,1,12,0,2},
        {4,3,0,0,2,0},
    };*/
    /*int graph[Max][Max] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };*/
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    primMST(vertex,graph);
    return 0;
}
