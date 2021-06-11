#include <stdio.h>
void quicksort(int a[],int lower,int upper);
int partition(int a[],int lower,int upper);
main()
{
	int upper,lower,a[100],n,m;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("Enter the nums:");
	for(m=0;m<n;m++)
	{
		scanf("%d",&a[m]);
	}
	printf("Sorted array:\n");
	quicksort(a,0,n-1);
	for(m=0;m<n;m++)
	{
		printf("%d\n",a[m]);
	}
}
void quicksort(int a[],int lower,int upper)
{
	int k;
	if(upper>lower)
	{
		k=partition(a,lower,upper);
		quicksort(a,lower,k-1);
		quicksort(a,k+1,upper);
		
	}
}
int partition(int a[],int lower,int upper)
{
	int p,q,i,swap,temp;
	p=lower;
	q=upper+1;
	i=a[lower];
	do
	{
		while(a[++p]<i);
		while(a[--q]>i);
		if(q>p)
		{
			swap=a[p];
			a[p]=a[q];
			a[q]=swap;
		}
	}while(q>=p);
	temp=a[lower];
	a[lower]=a[q];
	a[q]=temp;
	return(q);
}
