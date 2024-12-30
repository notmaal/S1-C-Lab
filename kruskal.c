#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int graph[100][100] = {0}, vertices, result[100][100] = {0};

void createGraph()
{
    int a, b, i = 0;
    while (1)
    {
        int weight;

        printf("Enter the first end point of the edge (Enter -1 to exit): ");
        scanf("%d", &a);
        if (a == -1)
            break;
        printf("Enter the second end point of the edge: ");
        scanf("%d", &b);
        if (a >= vertices || b >= vertices || a < 0 || b < 0)
        {
            printf("\ninvalid choice\n");
        }
        else
        {
            if (graph[a][b] > 0)
            {
                printf("\nThe edge already exists!!\n");
            }
            else
            {
                printf("Enter the weight of the edge: ");
                scanf("%d", &weight);
                graph[a][b] = weight;
                graph[b][a] = weight;
            }
        }
    }
}

void displayGraph(int arr[100][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int find(int x,int parent[]){
    return parent[x];
}

int uni(int x,int y,int parent[])
{
    int parent_x = find(x, parent);
    int parent_y = find(y, parent);
    if(parent_x == parent_y){
        return 0;
    }
    else{
        parent[x] = parent_y;
        return 1;
    }
}

void kruskal()
{
    int min, v, u;
    int parent[vertices];
    for(int i = 0; i <vertices; i++){
        parent[i] = i;
    }
    while (1)
    {
        min = INT_MAX;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = i; j < vertices; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (min == INT_MAX)
        {
            break;
        }
        else
        {
            graph[u][v] = INT_MAX;
            graph[v][u] = INT_MAX;
            if (uni(u, v, parent))
            {
                result[u][v] = 1;
                result[v][u] = 1;
            }
        }
    }
}

int main()
{
    printf("How many vertices are there? :");
    scanf("%d", &vertices);
    createGraph();
    printf("\nThe graph is: \n");
    displayGraph(graph, vertices);
    kruskal();
    printf("\nThe minimum spanning tree is: \n");
    displayGraph(result, vertices);
}