#include<stdio.h>

void selection(int *, int);
void swap(int *, int *);

int main()
{
    int arr[20];
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    selection(arr, n);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int *arr, int n)
{
    int i, j, min_idx;
    for(i=0; i<n; i++)
    {
        min_idx = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }

    printf("After selection sort:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}