#include <stdio.h>
#include <limits.h>

void print(int n, int mat[100][100])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf("****\t");
				
			}
			else
			{
				printf("%d\t",mat[i][j]);
			}
		}
		printf("\n");
	}
}

void mul_matrix(int n, int p[], int m[100][100], int s[100][100])
{
	int i,l,j,k,q;
	for(i=1; i<=n; i++)
	{
		m[i][i] = 0;
		
	}
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)
		{
			j = i+l-1;
			m[i][j] = INT_MAX;
			for(k = i; k<=j-1; k++)
			{
				q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("\n\n***********M Table**********\n");
	print(n,m);
	printf("\n\n***********S Table**********\n");
	print(n,s);
	
	
}

void print_optimal_parens(int s[100][100], int i, int j)
{
	if (i==j)
	{
		printf("A%d",i);
		
	}
	else
	{
		printf("(");
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j]+1, j);
		printf(")");
	}
}

main()
{
	int n,i,q,j, p[100],m[100][100],s[100][100];
	printf("\nEnter no. of dimensions:");
	scanf("%d",&q);
	printf("\nEnter dimensions:\n");
	for(i=0;i<q;i++)
	{
		scanf("%d",&p[i]);
		
	}
	n = q - 1;
	mul_matrix(n,p,m,s);
	printf("\nParenthesizing Sequence:\n");
	i=1;
	j=n;
	print_optimal_parens(s,i,j);
}
