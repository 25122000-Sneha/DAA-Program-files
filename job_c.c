#include <stdio.h>
#define MAX 100

struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencing(struct Job jobs[], int n);

int min(int x, int y) {
  if(x < y) return x;
  return y;
}

main() 
{
  
  int i, j, n;
  struct Job temp;
  struct Job jobs[10];
	
	printf("Enter no. of jobs:\n");
	scanf("%d", &n);
	printf("Enter jobs (order: id deadline profit):\n");
	for (i = 0; i < n; i++)
	{
	
		scanf("%s%d%d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
	}

 
  for(i = 0; i < n - 1; i++) 
  {
    for(j = 0; j < n - i - 1 ; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%s %s %s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%s\t%d\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencing(jobs, n);
}

void jobSequencing(struct Job jobs[], int n) {
  
  int i, j, k, profit;

 
  int slot[MAX];

  
  int filledTimeSlot = 0;

 
  int max_deadline = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > max_deadline) {
      max_deadline = jobs[i].deadline;
    }
  }

 
  for(i = 1; i <= max_deadline; i++) {
    slot[i] = -1;
  }

  printf("max deadline: %d\n", max_deadline);

  for(i = 1; i <= n; i++) {
    k = min(max_deadline, jobs[i - 1].deadline);
    while(k >= 1) {
      if(slot[k] == -1) {
        slot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    
    if(filledTimeSlot == max_deadline)
	{
      break;
    }
  }

 
  printf("\nJob sequence: ");
  for(i = 1; i <= max_deadline; i++)
  {
    printf("%s", jobs[slot[i]].id);

    if(i < max_deadline) {
      printf(" --> ");
    }
  }

  
  profit = 0;
  for(i = 1; i <= max_deadline; i++)
  {
    profit = profit + jobs[slot[i]].profit;
  }
  printf("\nMaximum Profit: %d\n", profit);
}

