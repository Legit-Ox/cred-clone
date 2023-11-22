// CSE332 OS : Assignment 3

// Assignment 3
// Question 4

// Name - Kathan Dave
// Roll Number - AU2140113
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void firstComeFirstServe(int n, int burst_t[], int arrival_t[])
{
    int wait_t[n], turnaround_t[n];
    int temp, i, j;
    float avg_wait_t, avg_turnaround_t, wsum = 0, tsum = 0;

    // Sorting processes by arrival time
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arrival_t[i] > arrival_t[j])
            {
                temp = arrival_t[j];
                arrival_t[j] = arrival_t[i];
                arrival_t[i] = temp;
                temp = burst_t[j];
                burst_t[j] = burst_t[i];
                burst_t[i] = temp;
            }
        }
    }
    temp = 0;
    wait_t[0] = 0;
    turnaround_t[0] = burst_t[0];
    tsum = burst_t[0];
    for (int i = 1; i < n; i++)
    {
        temp += burst_t[i - 1];
        wait_t[i] = temp - arrival_t[i];
        turnaround_t[i] = wait_t[i] + burst_t[i];
        wsum += wait_t[i];
        tsum += turnaround_t[i];
    }
    // Print the results
    printf("\n_________________________________________________________");
    printf("\n-------Result-------");
    printf("\n_________________________________________________________");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around");
    for (i = 0; i < n; i++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d", i + 1, burst_t[i], arrival_t[i], wait_t[i], turnaround_t[i]);
    }
    avg_wait_t = wsum / n;
    avg_turnaround_t = tsum / n;
    printf("\n\nAVERAGE WAITING TIME: %f\n", avg_wait_t);
    printf("\nAVERAGE TURN AROUND TIME: %f\n", avg_turnaround_t);
}

int main(int argc, char const *argv[])
{
    int n;
    printf(" -------First Come First Serve Scheduling-------\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_t[n], arrival_t[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst_t[i]);
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &arrival_t[i]);
    }

    firstComeFirstServe(n, burst_t, arrival_t);

    return 0;
}
