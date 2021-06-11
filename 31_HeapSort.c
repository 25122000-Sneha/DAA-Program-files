#include <stdio.h>
void build_heap(int a[], int n);
void heapify(int a[], int n, int i);
main()
{
	int a[100], n, m;
	printf("\nEnter no. of elements:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(m=0;m<n;m++)
	{
		scanf("%d",&a[m]);
	}
	build_heap(a, n);
	printf("\nSorted list in order:\n");
	for(m=0; m<n; m++)
	{
		printf("%d\n", a[m]);
	}
}

void build_heap(int a[], int n)
{
	int i, temp;
	for(i=n/2-1; i>=0; i--)
	{
		heapify(a, n, i);
	}
	for(i=n-1; i>=0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		
		heapify(a, i, 0);
	}
}
 
void heapify(int a[], int n, int i)
{
	int largest, left, right, swap;
	largest = i;
	left = (2*i) + 1;
	right = (2*i) + 2;
	
	if(left < n && a[left]>a[largest])
	{
		largest = left;
		
	}
	if(right < n && a[right]>a[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		swap = a[i];
		a[i] = a[largest];
		a[largest] = swap;
		
		heapify(a, n, largest);
	}
}
