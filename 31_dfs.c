#include <stdio.h>
#include <process.h>
#define MAX 100
#define begin 1
#define processed 3
#define wait 2

int v,e,n;
int mat[100][100],stack[100],visited[100];
int top = -1;

int empty_stack()
{
	if (top==-1)
	{
		return 1;
	}
	return 0;
}


void push(int val)
{
	if(top>=MAX-1)
	{
		printf("\nStack Overflow");
		exit(0);
		
	}
	else
	{
		top=top+1;
		stack[top]=val;
	}
}

int pop()
{
	int val;
	if(top==-1)
	{
		printf("\nStack underflow");
	}
	else
	{
		val=stack[top];
		top=top-1;
	}
	return val;
}




void dfs(int v)
{
	int i;
	push(v);
	while(empty_stack()!=1)
	{
		v = pop();
		if(visited[v] == begin)
		{
			printf(" %d",v);
			visited[v] = processed;
		}
		for(i=n;i>=1;i--)
		{
			if(mat[v][i]==1 && visited[i]==begin)
			{
				push(i);
			}
		}
	}
}


void dfs_search()
{
	int v;
	for(v=1;v<=n;v++)
	{
		visited[v] = begin;
	}
	printf("\nEnter starting vertex:");
	scanf("%d",&v);
	dfs(v);
}






main()
{
	int i,v1,v2,j;
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter no. of edges:");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter edge %d:",i);
		scanf("%d%d",&v1,&v2);
		mat[v1][v2] = 1;
	}
	printf("\nAdjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	dfs_search();
}

/*
Enter no. of vertices:8

Enter no. of edges:20

Enter edge 1:1 2

Enter edge 2:2 1

Enter edge 3:1 3

Enter edge 4:3 1

Enter edge 5:2 4

Enter edge 6:4 2

Enter edge 7:2 5

Enter edge 8:5 2

Enter edge 9:4 8

Enter edge 10:8 4

Enter edge 11:5 8

Enter edge 12:8 5

Enter edge 13:3 6

Enter edge 14:6 3

Enter edge 15:3 7

Enter edge 16:7 3

Enter edge 17:6 8

Enter edge 18:8 7

Enter edge 19:8 6

Enter edge 20:7 8
*/
