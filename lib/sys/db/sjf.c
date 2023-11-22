#include<stdio.h>

int main() {
    int bt[10] = {0}, tat[10] = {0}, wt[10] = {0}, p[10];
    int n, i, j;
    float atat = 0, awt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter burst time for each process:\n\n");
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", p[i]);
        scanf("%d", &bt[i]);
        printf("\n");
    }

    int temp;

    // Sorting of Processes and burst times
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Waiting time and Turnaround time of processes
    for (j = 0; j < n; j++) {
        wt[j] = 0;
        tat[j] = 0;
        for (i = 0; i < j; i++) {
            wt[j] = wt[j] + bt[i];
        }
        tat[j] = wt[j] + bt[j];
        awt += wt[j];
        atat += tat[j];
    }

    printf("\nSolution: \n\n");
    printf("P#\t BT\t TAT\t WT\t\n\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\n", p[i], bt[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time = %f\n", atat / n);
    printf("Average Waiting Time = %f\n\n", awt / n);

    return 0;
}

/*The program utilizes the Shortest Job Next (SJN) scheduling algorithm to streamline process execution. It prompts users for process details, sorts them by burst times, and calculates concise waiting and turnaround times. The algorithm prioritizes shorter tasks, aiming to minimize processing time.*/