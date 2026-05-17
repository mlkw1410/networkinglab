#include <stdio.h>

int main()
{
    int n, cost[10][10], distance[10], visited[10], pred[10];
    int i, j, count, min_distance, next_node = 0, src;

    printf("enter the number of nodes: ");
    scanf("%d", &n);

    printf("enter the cost matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    printf("enter the source node: ");
    scanf("%d", &src);

    for(i=0; i<n; i++)
    {
        distance[i] =cost[src][i];
        pred[i] = src;
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < n-1)
    {
        min_distance = 999;
        
        for (i=0; i<n; i++)
        {
            if(distance[i] < min_distance && !visited[i])
            {
                min_distance = distance[i];
                next_node = i;
            }
        }

        visited[next_node] =1;

        for(i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if (min_distance + cost[next_node][i] < distance[i])
                {
                    distance[i] = min_distance +cost[next_node][i];
                    pred[i] = next_node;
                }
            }
        }
        count++;
    }

    for (i=0; i<n; i++)
    {
        if(i!=src)
        {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\npath = %d", i);
            j=i;
            do 
            {
                j= pred[j];
                printf("<-%d", j);
            }while(j!=src);
        }
    }
    return 0;
}