#include<stdio.h>

void binary_search(int *, int, int);

int main()
{
    int arr[20];
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter a sorted array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int k;
    printf("Enter the key to find:\n");
    scanf("%d", &k);

    binary_search(arr, k, n);

    return 0;
}

void binary_search(int *arr, int k, int n)
{
    int low = 0;
    int high = n-1;
    int mid;

    int idx = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == k)
        {
            idx = mid;
            break;
        }

        if(k < arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }

    if(idx == -1)
        printf("Key not found in array.\n");
    else
        printf("Key found in array at index %d.\n", idx);
}