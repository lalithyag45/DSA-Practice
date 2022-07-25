#include<stdio.h>
int main()
{
    int cost[10][10],visited[10]={0},i, j, n, no_e=1,min,a,b,min_cost=0;
    printf("Enter number of nodes ");
    scanf("%d", &n);
    printf("Enter cost in form of adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
              cost[i][j]=100;
        }
    }   
visited[1]=1; // visited first node
    while(no_e<n)
    {
        min=1000;
        // in each cycle find minimum cost 
        for(i=1;i<=n; i++)
        {
            for(j=1;j<=n; j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        //if node is not visited
        if(visited[b]==0)
        {
            printf("\n %d to %d  cost=%d", a, b, min);
            min_cost=min_cost + min;
            no_e++;
        }
        visited[b]=1;
        cost[a][b]=cost[b][a]=100; 
    }
    printf("\n minimum weight is %d", min_cost);
    return 0;
}


