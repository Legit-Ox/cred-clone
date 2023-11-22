#include <stdio.h>

int main()
{
    int arrival[10], burst[10], remaining[10], turnaround[10], waiting[10], complete, i, shortest;
    int remain = 0, n, time, total_turnaround = 0, total_waiting = 0;

    printf("Enter no. of processes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        turnaround[i] = 0;
        waiting[i] = 0; // Initialize waiting time to 0
    }

    printf("\nGantt Chart:\n");
    printf("---------------\n");
    printf("| Time | Process |\n");
    printf("---------------\n");

    for (time = 0; remain != n; time++)
    {
        shortest = -1;

        for (i = 0; i < n; i++)
        {
            if (arrival[i] <= time && remaining[i])
            {
                if (shortest == -1 || remaining[i] < remaining[shortest])
                    shortest = i;
            }
        }

        if (shortest != -1)
        {
            printf("|  %2d  |   P%d   |\n", time, shortest + 1);
            remaining[shortest]--;

            if (remaining[shortest] == 0)
            {
                remain++;
                turnaround[shortest] = time + 1 - arrival[shortest];
                waiting[shortest] = turnaround[shortest] - burst[shortest];
                total_turnaround += turnaround[shortest];
                total_waiting += waiting[shortest];
            }
        }
        else
        {
            printf("|  %2d  |  Idle  |\n", time);
        }
    }

    printf("---------------\n");

    printf("\nProcess Table:\n");
    printf("------------------------------------------------------\n");
    printf("| Process | Arrival Time | Burst Time | Turnaround Time | Waiting Time |\n");
    printf("------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("|   P%d    |       %2d      |      %2d     |         %2d        |        %2d       |\n",
               i + 1, arrival[i], burst[i], turnaround[i], waiting[i]);
    }

    printf("------------------------------------------------------\n");

    // Calculate and display average turnaround time and waiting time
    float avg_turnaround = (float)total_turnaround / n;
    float avg_waiting = (float)total_waiting / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);

    return 0;
}

