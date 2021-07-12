#include <stdio.h>

int n,e,i,j,count = 1;
int mat[100][100], x[100];

void print(int x[], int n)
{
	printf("\nHamiltonian Cycle %d:\n",count);
	count++;
	
	for(i=1;i<=n+1;i++)
	{
		printf(" %d",x[i]);
	}
}

void nextValue(int k)
{
	while(1)
	{
		x[k] = (x[k] + 1) % (n+1);                  //next vertex
		if (x[k] == 0)                             //cannot find next value then return to hamiltonian and backtrack
		{
			return;
		}
		if(mat[x[k-1]][x[k]] != 0)                   //checking if consecutive vertices are connected by an edge
		{
			for(j=1;j<=k-1;j++)
			{
				if(x[j] == x[k])                    //check if already visited 
				break;
			}
			if (j==k)                              //terminating after for loop j increments to k
			{
			    if((k<n) | ((k==n) && (mat[x[n]][x[1]] != 0)))          //if k<n or if k is last vertex and check if it is connected to 1st vertex
				{
				    return;
			    }
			}
		
	    }
	}
}


void hamiltonian(int k)
{
	while(1)
	{
		nextValue(k);                 //assign valid next value for x[k]
		if(x[k]==0)                    //*backtrack*
		return;
		if(k==n)
		{
			print(x,n);
		}
		else
		{
			hamiltonian(k+1);
		}
	}
}






main()
{
	int v1,v2;
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter no. of edges:");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter edge %d:",i);
		scanf("%d%d",&v1,&v2);
		mat[v1][v2] = mat[v2][v1] = 1;
	}
	printf("\n***********Adjacency Matrix**********\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	x[1] = x[n+1] = 1;
	for(i=2;i<n+1;i++)
	{
		x[i] = 0;
	}
	hamiltonian(2);
}

/*
6

7

1 3

1 2

1 4

3 2

3 5

5 6

6 4
*/
