#include <stdio.h>
int n,m,i,j;
int mat[100][100];
int x[100],count=1;

void nextValue(int k)
{
	while(1)
	{
		x[k] = (x[k] + 1) % (m+1);               //next highest colour
		if(x[k] == 0)                              //all colours have been used
		return;
		for(j=1; j<=n; j++)
		{
			if((mat[k][j] != 0 ) && (x[k] == x[j]))
			{
				break;
			}
		}
		if(j==n+1)                                   //new colour found
		{
			return;
		}
	}
}


void print(int x[], int n)
{
	printf("\nColour Set %d\n",count++);
	for(i=1;i<=n;i++)
	{
		printf(" %d",x[i]);
	}
}



void mcolouring(int k)
{
	while(1)
	{
		nextValue(k);                     //assign to x[k] a legal colour
		if(x[k] == 0)  
		{
		    return;                        //no new colour possible
	    }
		if(k==n)                          //at most m colours have been used to colour n vertices
		{
			print(x,n);
		}
		else
		{
			mcolouring(k+1);
		}
	}
	
	
}



main()
{
	int v1,v2,e;
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter no. of edges:");
	scanf("%d",&e);
	printf("\nEnter max no. of colours:");
	scanf("%d",&m);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter edge %d:",i);
		scanf("%d%d",&v1,&v2);
		mat[v1][v2] = mat[v2][v1] = 1;
	}
	printf("\n--------Adjacency matrix-------------\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nColours assigned to the vertices are as follows:\n");
	mcolouring(1);
	
}
