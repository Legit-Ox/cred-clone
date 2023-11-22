#include <stdio.h>

int main()
{
	int arrival[10], burst[10], wait[10], start[10], turnaround[10];
	int remain = 0, n, time, i;
	printf("Enter no. of processes:");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
    	printf("Enter the arrival time for process P%d: ", i + 1);
    	scanf("%d", &arrival[i]);
    	printf("Enter the burst time for process P%d: ", i + 1);
    	scanf("%d", &burst[i]);
    	wait[i]=0; start[i]=0;
    	turnaround[i] = 0; 
	}

	printf("\nGantt Chart:\n");
	printf("---------------\n");
	printf("| Time | Process |\n");
	printf("---------------\n");

	while (remain != n)
	{
    	for (i = 0; i < n; i++)
    	{
		start[i] = time;
		wait[i]=start[i]-arrival[i];
		turnaround[i]=wait[i]+burst[i];
		printf("|  %2d  |   P%d   |\n", time, i + 1);
                time += burst[i];
                remain++;
    	}

        }

	printf("---------------\n");
	printf("\nProcess Table:\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("| Process | Arrival Time | Burst Time | Start Time | Wait Time | Turnaround Time |\n");
	printf("----------------------------------------------------------------------------------\n");

	for (i = 0; i < n; i++)
	{
    	printf("|   P%d	|   	%2d  	|  	%2d 	|     	%2d    	|     	%2d    	|     	%2d    	|\n",
           	i + 1, arrival[i], burst[i], start[i], wait[i], turnaround[i]);
	}

	printf("-----------------------------------------------------------------------------------\n");

	return 0;
}

