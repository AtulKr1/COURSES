#include <stdio.h>

struct node
{
    int id;
    int burst;
    int priority;
    int wt;
    int tat;
};
typedef struct node Task;

void swap(Task *, Task *);
void sort(Task *, int);
void priority(Task *, int);

int main()
{
    int n = 5;
    Task t[5];

    printf("Enter the Burst_Time and Priority of tasks:\n");
    for(int i=0; i<n; i++)
    {
        printf("Task %d: ", i);

        t[i].id = i;
        scanf("%d%d", &t[i].burst, &t[i].priority);
    }

    priority(t, n);

    return 0;
}

void swap(Task *a, Task *b)
{
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// To sort the tasks according to their arrival time
void sort(Task *list, int n)
{
    for(int i=0; i<n; i++)
    {
        int idx = i;
        for(int j=i+1; j<n; j++)
        {
            if(list[idx].priority > list[j].priority)
                idx = j;
        }

        if(idx != i)
            swap(&list[i], &list[idx]);
    }
}

void priority(Task *t, int n)
{
    sort(t, n);

    t[0].wt = 0;
    for(int i=1; i<n; i++)
        t[i].wt = t[i-1].wt + t[i-1].burst;

    for(int i=0; i<n; i++)
        t[i].tat = t[i].wt + t[i].burst;
    
    printf("Waiting Time:\n");
    double awt = 0;
    for(int i=0; i<n; i++)
    {
        printf("(%d: %d) ", t[i].id, t[i].wt);
        awt += (double)t[i].wt;
    }

    printf("\nTAT:\n");
    double tat = 0;
    for(int i=0; i<n; i++)
    {
        printf("(%d: %d) ", t[i].id, t[i].tat);
        tat += (double)t[i].tat;
    }

    awt /= n;
    tat /= n;

    printf("\nAWT: %lf\n", awt);
    printf("TAT: %lf\n", tat);
}