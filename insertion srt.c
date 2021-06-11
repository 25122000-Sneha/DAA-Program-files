#include <stdio.h>

main()
{
	int a[100],i,n,k,temp,ptr;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("Enter numbers:");
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&a[i]);
	}
	a[0]=-0;
	for(k=2;k<=n;k++)
	{
		temp=a[k];
		ptr=k-1;
		while(temp<a[ptr])
		{
			a[ptr+1]=a[ptr];
			ptr--;
    	}
     
    a[ptr+1]=temp;
	}
	printf("Sorted list in order:");
	for(i=1;i<=n;i++)
	{
		printf("\n%d",a[i]);
	}
}

