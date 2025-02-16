#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define Max 100


void dijkstra(int vertex,int graph[Max][Max])
{
    // The output array. dist[i] will hold the shortest distance from source to i
    int dist[vertex];
    //To represent set of vertices included in MST
    bool visited[vertex];
    //Array to store constructed MST


    for(int i=0; i<vertex; i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    // Distance of source vertex from itself is always 0
    dist[0]=0;

    for(int count=0; count<vertex-1; count++)
    {
        int u=minDistance(vertex,dist,visited);
        visited[u]=true;
        for(int j=0; j<vertex; j++)
        {
            if(graph[u][j]!=0 && visited[j]==false && (dist[u]+graph[u][j])<dist[j])
            {
                dist[j]=(dist[u]+graph[u][j]);
            }
        }
    }
    printSolution(vertex,dist,graph);

}


int minDistance(int vertex,int dist[],bool visited[])
{
    int min=INT_MAX;
    int min_key;
    for(int i=0; i<vertex; i++)
    {
        if(visited[i]==false && dist[i]<=min)
        {
            min=dist[i];
            min_key=i;
        }
    }
    return min_key;

}

void printSolution(int vertex,int dist[],int graph[Max][Max])
{
    printf("\nVertex \t\t Distance from Source\n\n");
    for (int i = 0; i < vertex; i++)
    {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
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
    /*int graph[Max][Max]={{0,2,0,0,0,4},
        {2,0,8,0,0,3},
        {0,8,0,6,1,0},
        {0,0,6,0,12,0},
        {0,0,1,12,0,2},
        {4,3,0,0,2,0},
    };*/
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    dijkstra(vertex,graph);
    return 0;
}

