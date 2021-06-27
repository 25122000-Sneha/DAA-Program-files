#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define begin 1
#define stand 2
#define mark 3

int mat[100][100];
int queue[100], visited[100];
int front=-1,rear=-1;
int i;
int m,n,v,e;




void insert(int num)
{
	if(rear==MAX-1)
	{
		printf("\nOverflow!! Unable to allocate memory");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=num;
	}
	else
	{
		rear=rear+1;
		queue[rear]=num;
	}
	
	
}


int dlt()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("\nUnderflow!! Queue is empty!!");
		exit(0);
		
	}
	else if(front==rear)
	{
		item=queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		item=queue[front];
		front=front+1;
	}
	return item;
}


int queue_empty()
{
	if (front==-1 || front>rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bfs(int i)
{
	int j;
	insert(i);
	visited[i] = stand;
	while(!queue_empty())
	{
		i = dlt();
		printf(" %d",i);
		visited[i] = mark;
		for(j=1; j<=n; j++)
		{
			
			if(mat[i][j]==1 && visited[j]==begin)
			{
				insert(j);
				visited[j] = stand;
			}
		}
	}
	printf("\n");
	
}

void bfs_search()
{
	int i;
	for(i=0; i<n; i++)
	{
		visited[i] = begin;
		
	}
	printf("\n\nEnter start vertex:");
	scanf("%d",&i);
	bfs(i);
}


main()
{
	int v1,v2;
	printf("\nEnter no. of vertices(directed graph)):");
	scanf("%d",&n);
	printf("\nEnter no. of edges(directed graph):");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter edge %d:",i);
		scanf("%d%d",&v1,&v2);
		mat[v1][v2] = 1;
	}
	bfs_search();
	
}

/*
Enter no. of vertices(directed graph)): 8

Enter no. of edges(directed graph): 11

Enter edge 1:0 1

Enter edge 2:0 4

Enter edge 3:0 3

Enter edge 4:1 4

Enter edge 5:2 4

Enter edge 6:5 2

Enter edge 7:4 5

Enter edge 8:3 6

Enter edge 9:3 7

Enter edge 10:6 7

Enter edge 11:7 4
*/
