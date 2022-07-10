#include<stdio.h>
#define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int main() {
  int i, j,n;
  printf("Enter number of jobs: ");
  scanf("%d",&n);
  
  struct Job jobs[MAX];
  for(i = 0; i < n; i++ )
    {
        printf("\nEnter details of job %d\n\n", i+1);

        printf("Enter job name: ");
        scanf("%s",&jobs[i].id);

        printf("Enter deadline: ");
        scanf("%d", &jobs[i].deadline);

        printf("Enter profit: ");
        scanf("%d", &jobs[i].profit);
    }
  Job temp;
  //sort the jobs profit wise in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencingWithDeadline(jobs, n);

  return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) {
  int i, j, k, maxprofit;
  //free time slots
  int timeslot[MAX];
  //filled time slots
  int filledTimeSlot = 0;
  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 [-1 denotes EMPTY]
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("Maximum deadline : %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = jobs[i - 1].deadline;
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(",");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}


