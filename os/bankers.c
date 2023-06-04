#include <stdio.h>

int main()
{
    int allocation[50][50];
    int maximum[50][50];
    int need[50][50];
    int done = 0;
    int completed[50];
    int available[50];

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int m;
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the allocation of each resources:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process[%d]: ", i);
        completed[i] = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum required resource of each resources:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process[%d]: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    // Calculating the need of each resource

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    printf("Need array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("Bankers algorithm:\n");
    int i = 0;
    int flag = 0;
    while (done < n)
    {
        int k = i % n;
        if(k == 0)
        {
            if(flag == 1)
                break;
            else
                flag = 1;
        }

        if (completed[k] == 1){
            i++;
            continue;
        }
            
        int j;
        for (j = 0; j < m; j++)
        {
            if (need[k][j] > available[j])
                break;
        }

        if (j >= m)
        {
            for (j = 0; j < m; j++)
            {
                available[j] += need[i][j];
                need[k][j] = 0;
            }
            completed[k] = 1;
            printf("Process[%d] -> ", k);
            done++;
            flag = 0;
        }

        i++;
    }

    if(done < n)
        printf("\nDEADLOCK\n");

    return 0;
}