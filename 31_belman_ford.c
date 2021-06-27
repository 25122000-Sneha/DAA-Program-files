#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
	int s;
	int d;
	int w;
};

struct Graph
{
	int v;
	int e;
	struct Edge *edge;
	
};
struct Graph *g;
int i,j;

struct Graph *graph(int no_of_vertices, int no_of_edges)
{
	g = (struct Graph*)malloc(sizeof(struct Graph));
	g->v = no_of_vertices;
	g->e = no_of_edges;
	g->edge = (struct Edge*)malloc(no_of_edges*sizeof(struct Edge));
	return g;
}

void print(int n, int arr[], int source)
{
	for(i=1;i<=n;i++)
	{
		printf(" %d",arr[i]);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\nShortest path (%d,%d):%d",source,i,arr[i]);
	}
}

void Bellman_Ford(struct Graph *g, int no_of_vertices , int no_of_edges, int source)
{
	int parent[100], cost[100],src,dest,wt;
	for(i=1; i<=no_of_vertices; i++)
	{
		cost[i] = INT_MAX;
		parent[i] = 0;
	}
	cost[source] = 0;
	parent[source] = -1;
	
	//filling up cost and parent array
	for(i=1; i<=no_of_vertices-1; i++)
	{
		for(j=0; j<no_of_edges; j++)
		{
			src = g->edge[j].s;
			dest = g->edge[j].d;
			wt = g->edge[j].w;
			if (cost[src]!=INT_MAX && (cost[src]+wt < cost[dest]))
			{
				cost[dest] = cost[src] + wt;
				parent[dest] = src;
			}
		}
	}
	
	//Checking if there is a negative weight cycle present
	for(i=0; i<no_of_edges; i++)
	{
		src = g->edge[i].s;
		dest = g->edge[i].d;
		wt = g->edge[i].w;
		if(cost[src]!=INT_MAX && (cost[src]+wt < cost[dest]))
		{
			printf("\nNegative weight cycle present!!");
			return;
		}
		
	}
	printf("\nNo negative weight cycle present :)");
	printf("\nShortest path costs:\n");
	print(no_of_vertices, cost,source);
	
}



main()
{
	int no_of_vertices, no_of_edges,source;
	printf("\nEnter no. of vertices:");
	scanf("%d",&no_of_vertices);
	printf("\nEnter no. of edges:");
	scanf("%d",&no_of_edges);
	
	g = graph(no_of_vertices, no_of_edges);
	
	printf("\nEnter source, destination, weight in order:\n");
	for(i=0; i < no_of_edges; i++)
	{
		scanf("%d%d%d",&g->edge[i].s, &g->edge[i].d, &g->edge[i].w);
	}
	printf("\nEnter source vertex:");
	scanf("%d",&source);
	
	
	
	Bellman_Ford(g,no_of_vertices,no_of_edges,source);
}



/*
no. of vertices = 6
no. of edges = 10
1 2 2
1 3 4
2 3 -3
2 4 1
2 5 5
3 4 -4
3 5 -2
4 6 8
5 4 4
5 6 6
*/
