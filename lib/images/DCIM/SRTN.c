// CSE332 OS : Assignment 3

// Assignment 3
// Question 2

// Name - Kathan Dave
// Roll Number - AU2140113
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void shortestRemainingTimeScheduling(int n, int burst_t[], int arrival_t[], int remain_t[])
{
    int a, b, btime = 0;
    int temp, w_time[n], t_time[n], ta = 0, sum = 0;
    float avg_wait_t = 0, avg_turnaround_t = 0, tsum = 0, wsum = 0;
    int complete = 0, t = 0, min_t = 99999;
    int shortest_job = 0, finish_t;

    while (complete != n)
    {
        for (b = 0; b < n; b++)
        {
            if ((arrival_t[b] <= t) && (remain_t[b] < min_t) && remain_t[b] > 0)
            {
                min_t = remain_t[b];
                shortest_job = b;
            }
        }
        remain_t[shortest_job]--;
        min_t = remain_t[shortest_job];
        if (min_t == 0)
        {
            min_t = 99999;
        }
        if (remain_t[shortest_job] == 0)
        {
            complete++;
            finish_t = t + 1;
            w_time[shortest_job] = finish_t - burst_t[shortest_job] - arrival_t[shortest_job];
            if (w_time[shortest_job] < 0)
            {
                w_time[shortest_job] = 0;
            }
        }
        t++;
    }

    for (a = 0; a < n; a++)
    {
        t_time[a] = burst_t[a] + w_time[a];
        ta = ta + t_time[a];
        wsum = wsum + w_time[a];
        tsum = tsum + t_time[a];
    }

    avg_wait_t = (wsum / n);
    avg_turnaround_t = (tsum / n);

    printf("\n_________________________________________________________");
    printf("\n-------Result-------");
    printf("\n_________________________________________________________");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around"); 
    for (a = 0; a < n; a++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d", a + 1, burst_t[a], arrival_t[a], w_time[a], t_time[a]);
    }
    printf("\n\nAVERAGE WAITING TIME: %f\n", avg_wait_t);
    printf("\nAVERAGE TURN AROUND TIME: %f\n", avg_turnaround_t);
}

int main(int argc, char const *argv[])
{
    int a, n;
    printf(" -------Shortest Remaining Time Scheduling ( NP )-------\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_t[n], arrival_t[n], remain_t[n];
    for (a = 0; a < n; a++)
    {
        printf("Enter the burst time of process %d: ", a + 1);
        scanf("%d", &burst_t[a]);
        printf("Enter the arrival time of process %d: ", a + 1);
        scanf("%d", &arrival_t[a]);
        remain_t[a] = burst_t[a];
    }

    shortestRemainingTimeScheduling(n, burst_t, arrival_t, remain_t);

    return 0;
}
