#include <stdio.h>
#include <process.h>
void bubble_sort_decreasing(float a[], float b[], float c[], int n);
void bubble_sort_increasing(float a[], float b[], float c[], int n);
void knapsack_3(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit);
void knapsack_1(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit);
void knapsack_2(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit);
main()
{
	int n, i, choice;
	float profit[100], weight[100], capacity, remainingSpace, knapsack[100], profit_ratio[100], totalProfit=0.0, copy[100];
	printf("Enter no. of items:"); 
	scanf("%d",&n);
	printf("\nEnter capacity of the knapsack:");
	scanf("%f",&capacity);
	for (i=0;i<n;i++)
	{
		printf("\nEnter value and weight of item %d: ",i+1);
		scanf("%f %f",&profit[i], &weight[i]);
		copy[i] = profit[i];
	} 
	while(1)
	{
		printf("\n\n*****MAIN MENU******");
		printf("\n1. Press 1 for Strategy 1\n2. Press 2 for strategy 2\n3. Press 3 for strategy 3\n4. Press -1 to exit\n");
		printf("\nEnter choice(1-4):");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\n-------Strategy 1---------");
			    knapsack_1(profit, weight, remainingSpace, profit_ratio, copy, knapsack, n, capacity, totalProfit);
			    break;
			case 2:
				printf("\n-------Strategy 2--------");
				knapsack_2(profit, weight, remainingSpace, profit_ratio, copy, knapsack, n, capacity, totalProfit);
				break;
			case 3:
				printf("\n--------Strategy 3--------");
				knapsack_3(profit, weight, remainingSpace, profit_ratio, copy, knapsack, n, capacity, totalProfit);
				break;
			case -1:
				printf("\n--------EXIT----------");
				exit(0);
			default:
				printf("Wrong choice!!");
				
		}
		
	}
	
}
void knapsack_3(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit)
{
	int i;
	for (i=0;i<n;i++)
	{
		profit_ratio[i] = profit[i]/weight[i];
	}
	bubble_sort_decreasing(profit_ratio, weight, profit, n);
	/*for(i=0;i<n;i++)
	{
		printf("Value=%f\tWeight=%f\tprofit ratio=%f\n", profit[i], weight[i], profit_ratio[i]);
	}*/
	for(i=0;i<n;i++)
	{
		knapsack[i] = 0.0;
	}
	printf("\n******Knapsack using Greedy strategy 3******\n");
	remainingSpace = capacity;
	
	for(i=0; ((i<n) && (remainingSpace > 0.0)); i++)
	{
		if(weight[i] < remainingSpace)
		{
			knapsack[i] = 1.0;
			remainingSpace = remainingSpace - weight[i];
		}
		else
		{
			knapsack[i] = remainingSpace/weight[i];
			remainingSpace = 0.0;
		}
		
		
	}
	printf("\nSolution set:\n");
	for(i=0;i<n;i++)
		{
			totalProfit = totalProfit + profit[i]*knapsack[i];
			printf("%f\n",knapsack[i]);
		}
	printf("\nTotal Profit: %f",totalProfit);
	
	
}
void knapsack_1(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit)
{
	int i;
	for (i=0;i<n;i++)
	{
		profit_ratio[i] = profit[i]/weight[i];
	}
	bubble_sort_decreasing(profit, weight, profit_ratio, n);
	/*for(i=0;i<n;i++)
	{
		printf("Value=%f\tWeight=%f\n", profit[i], weight[i]);
	}*/
	for(i=0;i<n;i++)
	{
		knapsack[i] = 0.0;
	}
	printf("\n******Knapsack using Greedy strategy 1******\n");
	remainingSpace = capacity;
	
	for(i=0; ((i<n) && (remainingSpace > 0.0)); i++)
	{
		if(weight[i] < remainingSpace)
		{
			knapsack[i] = 1.0;
			remainingSpace = remainingSpace - weight[i];
		}
		else
		{
			knapsack[i] = remainingSpace/weight[i];
			remainingSpace = 0.0;
		}
		
		
	}
	printf("\nSolution set:\n");
	for(i=0;i<n;i++)
		{
			totalProfit = totalProfit + profit[i]*knapsack[i];
			printf("%f\n",knapsack[i]);
		}
	printf("\nTotal Profit: %f",totalProfit);
	
}

void knapsack_2(float profit[], float weight[], float remainingSpace, float profit_ratio[], float copy[], float knapsack[], int n, float capacity, float totalProfit)
{
	int i;
	bubble_sort_increasing(weight, profit, profit_ratio, n);
	/*for(i=0;i<n;i++)
	{
		printf("Value=%f\tWeight=%f\n", profit[i], weight[i]);
	}*/
	for(i=0;i<n;i++)
	{
		knapsack[i] = 0.0;
	}
	printf("\n******Knapsack using Greedy strategy 2******\n");
	remainingSpace = capacity;
	
	for(i=0; ((i<n) && (remainingSpace > 0.0)); i++)
	{
		if(weight[i] < remainingSpace)
		{
			knapsack[i] = 1.0;
			remainingSpace = remainingSpace - weight[i];
		}
		else
		{
			knapsack[i] = remainingSpace/weight[i];
			remainingSpace = 0.0;
		}
		
		
	} 
	printf("\nSolution set:\n");
	for(i=0;i<n;i++)
		{
			totalProfit = totalProfit + profit[i]*knapsack[i];
			printf("%f\n",knapsack[i]);
		}
	printf("\nTotal Profit: %f",totalProfit);
	
	
	
}

void bubble_sort_decreasing(float a[], float b[], float c[], int n)
{
    int temp, i, j;
	float swap;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
				
				swap=b[j];
				b[j]=b[j+1];
				b[j+1]=swap;
				
				swap=c[j];
				c[j]=c[j+1];
				c[j+1]=swap;
			}
		}
	}
}
void bubble_sort_increasing(float a[], float b[], float c[], int n)
{
    int temp, i, j;
	float swap;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
				
				swap=b[j];
				b[j]=b[j+1];
				b[j+1]=swap;
				
				swap=c[j];
				c[j]=c[j+1];
				c[j+1]=swap;
			}
		}
	}
}
