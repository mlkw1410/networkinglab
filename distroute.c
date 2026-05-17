#include <stdio.h>

struct router{
    unsigned cost[20];
    unsigned from[20];
} routingTable[10];

int main()
{
    int costmat[20][20];
    int routers, i, j, k;
    printf("no.of routers: ");
    scanf("%d", &routers);

    printf("enter the cost matrix: \n");
    for(i = 0; i<routers; i++)
    {
        for(j=0; j<routers; j++)
        {
            scanf("%d", &costmat[i][j]);
            routingTable[i].cost[j] = costmat[i][j];
            routingTable[i].from[j] =j;
        }
    }

    int otherShorterpathexists;

    do 
    {
        otherShorterpathexists =0;
        for(i=0; i<routers; i++)
        {
            for(j=0; j<routers; j++)
            {
                for(k=0; k<routers; k++)
                {
                     if(routingTable[i].cost[j] > costmat[i][k]+routingTable[k].cost[j])
                     {
                        routingTable[i].cost[j] = costmat[i][k]+routingTable[k].cost[j];
                        routingTable[i].from[j]= k;
                        otherShorterpathexists = 1;
                     }
                }
            }
        }
    }while(otherShorterpathexists != 0);
    
    for(i=0; i<routers; i++)
    {
        printf("router %d: ", i);
        for(j=0; j<routers; j++)
        {
            printf("router %d via router %d with distance %d\n ", j+1, routingTable[i].from[j]+1, routingTable[i].cost[j]);
        }
    }
    printf("\n");
}