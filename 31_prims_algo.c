#include <stdio.h>  
#include <limits.h>  
int n,e; 
  
int minkey(int key[], int set[])  
{  
   int min  = INT_MAX, index,i;  
   
   for (i = 0; i < n; i++) 
   {
        if (set[i] == 0 && key[i] < min ) 
	    {
            min  = key[i];
			index = i; 
	    }
   }
   
   return index;  
}  
  
   
void prim(int g[][100])  
{  
    int parent[n];   
    int key[n];     
    int set[n];    
    int i, count,u,v;   
    for (i = 0; i < n; i++) 
	{
	    key[i] = INT_MAX;
		set[i] = 0; 
    }
   
    key[0] = 0;       
    parent[0] = -1;   
   
    for (count = 0; count < n-1; count++)  
    {  
	    u = minkey(key, set);  
        set[u] = 1;  
   
        for (i = 0; i < n; i++)  
        {
            if (g[u][i] && set[i] == 0 && g[u][i] <  key[i])  
            {
                parent[i]  = u;
				key[i] = g[u][i];
            }
		}
    }  
    int sum = 0;
    printf("\n\nMinimum spanning tree:\n");
    printf("v1\tv2\tcost\n");
    for (i = 1; i < n; i++)  
    {
        printf("%d\t%d\t%d \n", parent[i], i, g[i][parent[i]]); 
		sum = sum + g[i][parent[i]]; 
    }
    printf("\nMinimum cost = %d",sum);
}  
   
   
main()  
{  
   int cost,i,j,p,g[100][100];
   printf("\nEnter no. of vertices:");
   scanf("%d",&n);
   printf("\nEnter no. of edges:");
   scanf("%d",&e);
   for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			g[i][j] = 0;
			
		}
	}
   printf("\n******Order(v1,v2,cost)*******");
	for(p=0;p<e;p++)
	{
		printf("\nEnter edge %d:",p);
		scanf("%d%d%d",&i,&j,&cost);
		g[j][i] = g[i][j] = cost;
	}
	printf("\n*******************Adjacency matrix********************\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
    prim(g);  
}  
/*
6

11

0 1 2

0 2 4

0 3 3

1 2 5

1 3 2

1 4 5

2 5 5

5 4 7

4 3 6

2 3 3

3 5 4
*/
