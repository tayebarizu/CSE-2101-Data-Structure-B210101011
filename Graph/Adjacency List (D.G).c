#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

typedef struct list
{
    Node *head;
} list;

void addNode(list *adj[])
{
    int v1,v2;
    Node *des,*temp,*src;
    scanf("%d %d",&v1,&v2);

    if(adj[v1]->head==NULL)
    {
        src=(Node*)malloc(sizeof(Node));
        src->vertex=v1;
        src->next=NULL;
        adj[v1]->head=src;
    }
    des=(Node*)malloc(sizeof(Node));
    des->vertex=v2;
    des->next=NULL;
    temp=adj[v1]->head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=des;

}

void print(list *adj[], int vertex)
{
    for(int i=0; i<vertex; i++)
    {
        Node *print=adj[i]->head;
        printf("Adjacency list for vertex %d:",i);
        while(print!=NULL)
        {
            printf("%d ",print->vertex);
            print=print->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertex,edge;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertex);
    printf("Enter the number of edges: ");
    scanf("%d",&edge);

    list *adj[vertex];

    for(int i=0; i<vertex; i++)
    {
        adj[i]=(list*)malloc(sizeof(list));
        adj[i]->head=NULL;
    }
    printf("Enter first and last vertices (Edges):\n");
    for(int i=0; i<edge; i++)
    {
        addNode(adj);
    }
    print(adj,vertex);

    return 0;

}
