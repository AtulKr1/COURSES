#include <stdio.h>

struct node
{
    int id;
    int burst;
    int wt;
    int tat;
};
typedef struct node Task;

void swap(Task *a, Task *b)
{
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// To sort the tasks according to their burst time
void sort(Task *list, int n)
{
    for(int i=0; i<n; i++)
    {
        int idx = i;
        for(int j=i+1; j<n; j++)
        {
            if(list[j].burst < list[idx].burst)
                idx = j;
        }

        if(idx != i)
            swap(&list[i], &list[idx]);
    }
}

int main()
{
    int n = 5;
    Task t[5];

    printf("Enter the Burst_Time of tasks:\n");
    for(int i=0; i<n; i++)
    {
        printf("Task %d: ", i);

        t[i].id = i;
        scanf("%d", &t[i].burst);
    }

    sort(t, n);

    int cur = 0;
    for(int i=0; i<n; i++)
    {
        t[i].wt = cur;
        cur += t[i].burst;
    }

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

    return 0;
}