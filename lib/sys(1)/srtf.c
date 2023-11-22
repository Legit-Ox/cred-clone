#include <stdio.h>

int main() {
    int arrivalTime[10], burstTime[10], remainingTime[10], completionTime[10], i, smallest;
    int remainingProcesses = 0, numProcesses, currentTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Number of Processes: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++) {
        printf("Arrival time for Process P%d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst time for Process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
        completionTime[i] = -1;  // Initialize completionTime to -1 for processes not completed
    }

    printf("\n\nGantt Chart:\n");
    while (remainingProcesses != numProcesses) {
        smallest = -1;

        for (i = 0; i < numProcesses; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] && (smallest == -1 || remainingTime[i] < remainingTime[smallest])) {
                smallest = i;
            }
        }

        if (smallest == -1) {
            printf("  Idle   ");
            currentTime++;
            continue;
        }

        printf("  P%d (%d)  ", smallest + 1, currentTime);
        remainingTime[smallest]--;
        currentTime++;

        if (remainingTime[smallest] == 0 && completionTime[smallest] == -1) {
            remainingProcesses++;
            completionTime[smallest] = currentTime;
        }
    }

    printf("\n\nProcess\t | Turnaround Time | Waiting Time\n\n");

    for (i = 0; i < numProcesses; i++) {
        totalWaitingTime += completionTime[i] - burstTime[i] - arrivalTime[i];
        totalTurnaroundTime += completionTime[i] - arrivalTime[i];

        printf("P[%d]\t |\t %d\t |\t %d\n", i + 1, completionTime[i] - arrivalTime[i], completionTime[i] - burstTime[i] - arrivalTime[i]);
    }

    printf("\n\nAverage waiting time = %.2f\n", (float)totalWaitingTime / numProcesses);
    printf("Average turnaround time = %.2f\n", (float)totalTurnaroundTime / numProcesses);

    return 0;
}

/*This C program utilizes the Shortest Job Next (SJN) scheduling algorithm to simulate the execution of processes. Users input the number of processes, arrival times, and burst times. The program calculates and displays turnaround and waiting times for each process, along with the average turnaround and waiting times. This information helps assess the efficiency of the SJN algorithm in minimizing process wait times.
*/