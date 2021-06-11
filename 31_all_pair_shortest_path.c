//All pair shortest path
//Floyd-Warshall's Algorithm
#include <stdio.h>

int min(int a, int b)
{
	if (a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void print(int n, int a[100][100])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void all_pair_shortest(int n, int a[100][100])
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{

				a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
			}
		}
		printf("\nMatrix A%d:\n",k);
		print(n,a);
	}
	
	
}

main()
{
	int n,e, a[100][100],i,j,k;
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter no. of edges:");
	scanf("%d",&e);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nEnter weight of edge(%d,%d):",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n******A0 matrix from input******\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	all_pair_shortest(n,a);
	
	
	
}
