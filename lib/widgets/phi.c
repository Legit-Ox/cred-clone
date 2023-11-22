#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t fork_philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t meals_eaten_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for accessing mealseaten
pthread_t philosophers[NUM_PHILOSOPHERS];
int philosopher_ids[NUM_PHILOSOPHERS];
int max_meals_tobe_eaten[NUM_PHILOSOPHERS] = {3, 4, 2, 5, 3}; // Maximum number of meals for each philosopher
int mealseaten[NUM_PHILOSOPHERS] = {0};                       // Number of meals eaten by each philosopher

void *philosopher(void *arg);
int main()
{
    // Initialize the forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_init(&fork_philosophers[i], NULL);
    }

    // Create the philosophers
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
	    }

    // Wait for the philosophers to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy the forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_destroy(&fork_philosophers[i]);
    }

    return 0;
}
void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int leftfork = id;
    int rightfork = (id + 1) % NUM_PHILOSOPHERS;

    while (mealseaten[id] < max_meals_tobe_eaten[id])
    {
        // Try to pick up the left fork
        pthread_mutex_lock(&fork_philosophers[leftfork]);

        // Try to pick up the right fork
        if (pthread_mutex_trylock(&fork_philosophers[rightfork]) != 0)
        {
            // Failed to pick up the right fork, release the left fork
            pthread_mutex_unlock(&fork_philosophers[leftfork]);
            continue;
        }

        // Both forks have been picked up, eat
        mealseaten[id]++;
        printf("Philosopher %d is eating (Meals eaten till now : %d)\n", id, mealseaten[id]);

        // Release the forks
        pthread_mutex_unlock(&fork_philosophers[leftfork]);
        pthread_mutex_unlock(&fork_philosophers[rightfork]);

        // Think for a bit before eating again
        usleep(1000 * (rand() % 100));
    }

    printf("Philosopher %d has finished eating (Total meals eaten after finish : %d)\n", id, mealseaten[id]);

    return NULL;
}




