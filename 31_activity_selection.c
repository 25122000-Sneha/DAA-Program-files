#include <stdio.h>

void print(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
int partition(int f[], int s[], int activity[], int low, int high)
{
	int pivot,swap,temp, i, j;
	pivot = f[high];
	i = low - 1;
	for(j=low; j<=high - 1; j++)
	{
		if(f[j] <= pivot)
		{
			i++;
			swap = f[i];
			f[i] = f[j];
			f[j] = swap;
			
			swap = s[i];
			s[i] = s[j];
			s[j] = swap;
			
			swap = activity[i];
			activity[i] = activity[j];
			activity[j] = swap;
		}
	}
	temp = f[i+1];
	f[i+1] = f[high];
	f[high] = temp;
	
	temp = s[i+1];
	s[i+1] = s[high];
	s[high] = temp;
	
	temp = activity[i+1];
	activity[i+1] = activity[high];
	activity[high] = temp;
	
	return (i+1);
}
void quick_sort(int f[], int s[], int activity[], int low, int high)
{
	int k;
	if(low<high)
	{
		k = partition(f,s,activity,low,high);
		quick_sort(f,s,activity,low,k-1);
		quick_sort(f,s,activity,k+1,high);
		
		
	}
	
}

void activity_selection(int s[], int f[], int activity[], int n)
{
	int i,j, select[100];
	printf("\nFollowing activities are selected:\n");
	i = 0;
	printf("%d",activity[0]);
	
	for(j=1;j<n;j++)
	{
		if(s[j] >= f[i])
		{
			printf(", %d",activity[j]);
			i = j;
		}
	}
	
}


main()
{
	int s[100], f[100], activity[100], n, i;
	printf("\nEnter no. of activities:");
	scanf("%d",&n);
	printf("\nEnter details of all activities(serial no., start time, finishing time):\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&activity[i],&s[i],&f[i]);
	}
	
	printf("\nSorting in order of increasing finishing time:\n");
	quick_sort(f,s,activity,0,n-1);
	printf("\nActivities in sorted order:\n");
	print(activity,n);
	printf("\nFinishing time in sorted order:\n");
	print(f, n);
	
	printf("\nCorresponding Starting times:\n");
	print(s, n);
	activity_selection(s,f,activity,n);
}
