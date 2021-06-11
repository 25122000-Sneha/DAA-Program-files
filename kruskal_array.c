#include <stdio.h>

int graph[100][100], parent[100];
int i, j, n, u, v, a, b, min, min_wt = 0;;
void print(int graph[][100], int n)
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
}

int find_parent(int i)
{
	while(parent[i])
	{
		i = parent[i];
		
	}
	return i;
}

int union1(int i, int j)
{
	if(i!=j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}

void kruskal(int graph[][100], int n)
{
	int ne=1;
	printf("\n\nMinimum spanning tree will have following edges and corresponding weights:\n");
	while(ne<n)                               
	{
		for(i=1, min = 999; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(graph[i][j] < min)
				{
					min = graph[i][j];                //find minimum edge from matrix
				    a = u = i;
				    b = v = j;
				}
			}
		}
	
	u = find_parent(u);               //find parent of source vertex
	v = find_parent(v);               // find parent of destination vertex
    if(union1(u,v))
    {
    	printf("\nEdge %d ---> (%d, %d), Weight = %d", ne,a,b,min);
    	ne++;
    	min_wt+=min;
	}
	graph[a][b] = graph[b][a] = 999;
   }
   printf("\nMinimum weight = %d", min_wt);
}
main()
{
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix of the graph:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&graph[i][j]);
			if(graph[i][j] == 0)
			{
				graph[i][j] = 999;
			}
		}
	}
	printf("\nAdjacency matrix:\n");
	print(graph, n);
	kruskal(graph, n);
}
