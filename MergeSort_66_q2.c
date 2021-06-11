#include <stdio.h>
void mergesort(int a[],int low,int high);
void merge(int a[],int low1,int high1,int low2,int high2);

main()
{
	int a[100],low,high,n,m;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(m=0;m<n;m++)
	{
		scanf("%d",&a[m]);
		
	}
	low=0;
	high=n-1;
	mergesort(a,low,high);
	printf("\nSorted array:\n");
	for(m=0;m<n;m++)
	{
		printf("%d\n",a[m]);
	}
	
}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid;
		mid=(high+low)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,mid+1,high);
	}
}
void merge(int a[],int low1,int high1,int low2,int high2)
{
	int temp[100];
	int i,j,k;
	i=low1;
	j=low2;
	k=0;
	while(i<=high1 && j<=high2)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=high1)
	{
		temp[k]=a[i];
		k++;
		i++;
		
	}
	while(j<=high2)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	j=0;
	for(i=low1;i<=high2;i++)
	{
		a[i]=temp[j];
		j++;
	}
}

