#include<stdio.h>

void bubble_sort(int *, int);
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

    bubble_sort(arr, n);

    return 0;
}

void bubble_sort(int *arr, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }

    printf("After bubble sort:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}