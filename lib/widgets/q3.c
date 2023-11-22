
#include <stdio.h>

int main() {
    int arrival[10], burst[10], remaining[10], turnaround[10], waiting[10],;
    int remain, n, time_quantum, i, time, total_turnaround = 0, total_waiting = 0;

    printf("Enter no. of processes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        turnaround[i] = 0;
        waiting[i] = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    remain = n;
    time = 0;

    printf("\nGantt Chart:\n");
    printf("---------------\n");
    printf("| Time | Process |\n");
    printf("---------------\n");

    while (remain != 0) {
    for (i = 0; i < n; i++) {
        if (remaining[i] > 0 && arrival[i] <= time) {
            int execution_time = (remaining[i] > time_quantum) ? time_quantum : remaining[i];

            printf("|  %2d  |   P%d   |\n", time, i + 1);

            remaining[i] -= execution_time;
            time += execution_time;

            if (remaining[i] == 0) {
                remain--;
                turnaround[i] = time - arrival[i];
                waiting[i] = turnaround[i] - burst[i];
                total_turnaround += turnaround[i];
                total_waiting += waiting[i];
            }
        }
    }
    // Reset i after processing each time slot
    i = 0;
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

    
    float avg_turnaround = (float)total_turnaround / n;
    float avg_waiting = (float)total_waiting / n;

    return 0;
}






