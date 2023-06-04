#include<stdio.h>

void linear_search(int *, int, int);

int main()
{
    int arr[20];
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int k;
    printf("Enter the key to find:\n");
    scanf("%d", &k);

    linear_search(arr, k, n);

    return 0;
}

void linear_search(int *arr, int k, int n)
{
    int i;
    int idx = -1;
    for(i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1)
        printf("Key not found in array.");
    else
        printf("Key found in array at index %d.", idx);
}