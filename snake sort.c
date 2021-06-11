#include <stdio.h>
#include<math.h>
int i, j, k, swap;
void print(int a[][100], int m, int n)
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void oddEvenSort(int a[][100], int size, int m, int n)
{
	for(i=0;i<m;i++)
	{
		if(i%2==0)
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
		else
		{
			for(j=0;j<n-1;j++)
			{
				for(k=0;k<n-j-1;k++)
				{
					if(a[i][k] < a[i][k+1])
					{
						swap = a[i][k];
						a[i][k] = a[i][k+1];
						a[i][k+1] = swap;
					}
				}
			}
		}
	}
	print(a, m, n);
	
}
void columnSort(int a[][100], int size, int m, int n)
{
	for(j=0;j<n;j++)
	{
		for(i=0;i<m-1;i++)
		{
			for(k=0;k<m-i-1;k++)
			{
				if(a[k][j] > a[k+1][j])
				{
					swap = a[k][j];
					a[k][j] = a[k+1][j];
					a[k+1][j] = swap;
				}
			}
		}
	}
	print(a, m, n);
}









main()
{
	int a[100][100],m,n, step, size;
	printf("\nEnter no. of rows:");
	scanf("%d",&m);
	printf("\nEnter no. of columns:");
	scanf("%d",&n);
	printf("\nEnter elements of matrix:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nInitial matrix:\n");
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	size = m*n;
	for(step = 1; step <= (log(size)/log(2) + 1); step++)
	{
		if(step%2!=0)
		{
			printf("\nPhase %d:\n",step);
			oddEvenSort(a, size, m, n);
		}
		else
		{
			printf("\nPhase %d:\n",step);
			columnSort(a, size, m, n);
		}
		
	}
}
