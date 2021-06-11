// Maximum and minimum using divide and conquer
#include <stdio.h>
void maxmin(int a[], int low, int high);
int max, min;
main()
{
	int a[100], n , i;
	printf("\nEnter no. of elements:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max = min =a[0];
	maxmin(a, 0, n-1);
	printf("\nMaximum: %d", max);
	printf("\nMinimum: %d", min);
}

void maxmin(int a[], int low, int high)
{
	int mid, max1, min1;
	if(low==high)
	{
		max = a[low];
		min = a[low];
	}
	else if(low == high - 1)
	{
		if(a[low] > a[high])
		{
			max = a[low];
			min = a[high];
		}
		else
		{
			max = a[high];
			min = a[low];
		}
	}
	else
	{
		mid = ((low+high)/2);
		maxmin(a, low, mid);
		max1 = max;
		min1 = min;
		maxmin(a, mid+1, high);
		if(max < max1)
		{
			max = max1;
		}
		if(min > min1)
		{
			min = min1;
		}
	}
}
