#include<stdio.h>

void extreme(int *, int);
void search(int *, int, int);
void sum_arr(int *, int);
void reverse(int *, int);

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[20];
    printf("Enter the array: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int k;
    printf("Enter element to find: ");
    scanf("%d", &k);

    extreme(arr, n);
    search(arr, k, n);
    sum_arr(arr, n);
    reverse(arr, n);

    return 0;
}

void extreme(int *arr, int n)
{
    int i;
    int lar=arr[0], sma=arr[0];
    for(i=1; i<n; i++)
    {
        if(arr[i] > lar)
            lar = arr[i];
        if(arr[i] < sma)
            sma = arr[i];
    }

    printf("Largest = %d\n", lar);
    printf("Smallest = %d\n", sma);
}

void search(int *arr, int k, int n)
{
    int i;
    int idx = -1;
    for(i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            idx = i;
        }
    }

    if(idx == -1)
        printf("Item not found\n");
    else
        printf("%d is at index %d\n", k, idx);
}

void sum_arr(int *arr, int n)
{
    int sum = 0;
    int i;

    for(i=0; i<n; i++)
        sum += arr[i];

    printf("Sum of array = %d\n", sum);
}

void reverse(int *arr, int n)
{
    int i, temp;

    printf("Before Swap:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    for(i=0; i<n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    printf("\nAfter Swap:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
}