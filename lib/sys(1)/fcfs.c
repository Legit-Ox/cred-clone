#include <stdio.h>

int main() {
    int at[10], bt[10], ct[10], wt[10], tt[10];
    int numProcesses, i;

    printf("Number of Processes: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++) {
        printf("Arrival time for Process P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate completion, waiting, and turnaround times
    ct[0] = at[0] + bt[0];
    tt[0] = ct[0] - at[0];
    wt[0] = tt[0] - bt[0];

    for (i = 1; i < numProcesses; i++) {
        ct[i] = ct[i - 1] + bt[i];
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i] > 0 ? tt[i] - bt[i] : 0;
    }

    // Print Gantt Chart
    printf("\n\nGantt Chart:\n");
    printf("|");
    for (i = 0; i < numProcesses; i++) {
        printf("  P%d (%d)  |", i + 1, ct[i]);
    }
    printf("\n");

    // Print Table
    printf("\nProcess\t | Turnaround Time | Waiting Time\n\n");
    for (i = 0; i < numProcesses; i++) {
        printf("P[%d]\t |\t %d\t |\t %d\n", i + 1, tt[i], wt[i]);
    }

    return 0;
}

/*This C program uses the First Come First Serve (FCFS) scheduling method to simulate process execution. Users input arrival and burst times, and the program calculates completion, turnaround, and waiting times. It displays a Gantt Chart and a table showcasing the order of execution and corresponding times for each process. FCFS ensures tasks are handled in the order of arrival, providing a simple scheduling approach.*/
