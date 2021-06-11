#include <stdio.h> 
int binary_search(int a[], int x, int beg, int end);
void bubble_sort(int a[], int n);
main() 
{
   int n, i, key, pos;
   int beg, end, a[100];
 
   printf("\nEnter the total number of elements:");
   scanf("%d", &n);
 
   printf("\nEnter the elements of list :");
   for (i = 0; i < n; i++) 
   {
      scanf("%d", &a[i]);
   }
 
   beg = 0;
   end = n - 1;
 
   bubble_sort(a, n);
   printf("\nSorted list in order:\n");
   for(i=0; i<n; i++)
   {
   	printf("\n%d",a[i]);
   }
   printf("\nEnter element to be searched : ");
   scanf("%d", &key);
   pos = binary_search(a, key, beg, end);
   
 
   if (pos != -1) 
   {
      printf("\nElement found at position %d", pos);
   } 
   else
   {
      printf("\nThe element is not present in the list");
   }
}
//Bubble sort
void bubble_sort(int a[], int n)
{
    int temp, i, j, swap;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}
		}
	}
}
// Binary Search function using recursion
int binary_search(int a[], int x, int beg, int end)
{
   int mid;
 
   if (beg > end)
   {
   
      return -1;
   }
 
   mid = (beg + end) / 2;
 
   if (x == a[mid]) 
   {
      return (mid);
   }
   else if (x < a[mid]) 
   {
      binary_search(a, x, beg, mid - 1);
   } 
   else 
   {
      binary_search(a, x, mid + 1, end);
   }
}
