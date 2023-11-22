#include <stdio.h>

int main() {
    int at[10], bt[10], rt[10], tt[10], wt[10], ct[10];
    int numProcesses, i, time_quantum, time;
    //taking input
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++) {
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        tt[i] = 0;
        wt[i] = 0;
    }
    //quantum
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int remain = numProcesses;
    time = 0;
    //chart display
    printf("\nGantt Chart:\n");
    printf("|");
    //main loop for rr
    while (remain != 0) {
        for (i = 0; i < numProcesses; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                int execution_time = (rt[i] > time_quantum) ? time_quantum : rt[i];

                printf("  P%d (%d)  |", i + 1, time + execution_time);

                rt[i] -= execution_time;
                time += execution_time;

                if (rt[i] == 0) {
                    remain--;
                    tt[i] = time - at[i];
                    wt[i] = tt[i] - bt[i] > 0 ? tt[i] - bt[i] : 0;
                    ct[i] = time;
                }
            }
        }
    }
    //printing table
    printf("\n\nProcess\t | Turnaround Time | Waiting Time\n\n");
    for (i = 0; i < numProcesses; i++) {
        printf("P[%d]\t |\t %d\t |\t %d\n", i + 1, tt[i], wt[i]);
    }

    return 0;
}

/*
This C program implements the Round Robin scheduling algorithm. It prompts the user for the number of processes, their arrival times, and burst times. The algorithm then simulates the execution, producing a Gantt Chart to display the order in which processes are executed. It calculates turnaround and waiting times for each process*/
