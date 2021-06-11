// Row wise and column wise sorting of matrix
#include <stdio.h>

main()
{
	int a[100][100], transposed[100][100],ultimate[100][100], m, n, i, j, k, swap;
	printf("\nEnter no. of rows:");
	scanf("%d",&m);
	printf("\nEnter no. of columns:");
	scanf("%d", &n);
	printf("\nEnter elements:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nInitial Matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nRow wise sorting:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			for(k=0;k<n-j-1;k++)
			{
				if(a[i][k] > a[i][k+1])
				{
					swap = a[i][k];
					a[i][k] = a[i][k+1];
					a[i][k+1] = swap;
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	//printf("\nTranspose of the matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			transposed[i][j] = a[j][i];
		}
		
	}
	
	//printf("\nAgain Sorting the rows in ascending order\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
			for(k=0;k<m-j-1;k++)
			{
				if(transposed[i][k] > transposed[i][k+1])
				{
					swap = transposed[i][k];
				    transposed[i][k] = transposed[i][k+1];
				    transposed[i][k+1] = swap;
				}
			}
		}
	}
	
	//printf("\nTranspose again:\n");
	printf("\nColumn wise sorting:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ultimate[i][j] = transposed[j][i];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",ultimate[i][j]);
		}
		printf("\n");
	}

}
