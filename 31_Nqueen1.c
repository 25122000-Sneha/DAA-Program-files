#include<stdio.h>
#include<math.h>
 
void print(int n); 
int place(int row,int column);
void Nqueen(int row,int n);
 
int x[20],count=1;
 
main()
{
int n,i,j;
printf("\nEnter no. of queens:");
scanf("%d",&n);
Nqueen(1,n);
}
 

void print(int n)
{
	int i;
	printf("\nSolution %d:\n",count++);
	for(i=1;i<=n;i++)
	{
		printf(" %d",x[i]);
	}
}
 

int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  
  if(x[i]==column)
   return 0;
  else
   if(abs(x[i]-column)==abs(i-row))
    return 0;
}
 
return 1; 
}
 

void Nqueen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   x[row]=column; 
   if(row==n) 
    print(n); 
   else 
    Nqueen(row+1,n);
  }
}
}
