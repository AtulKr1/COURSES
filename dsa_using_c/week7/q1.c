#include<stdio.h>

void merge(int *, int *, int, int);

int main()
{
    int arr1[20], arr2[20];
    int n1, n2, i;
    printf("Enter the size of array 1: ");
    scanf("%d", &n1);
    printf("Enter a sorted array 1:\n");
    for(i=0; i<n1; i++)
        scanf("%d", &arr1[i]);
    printf("Enter the size of array 2: ");
    scanf("%d", &n2);
    printf("Enter a sorted array 2:\n");
    for(i=0; i<n2; i++)
        scanf("%d", &arr2[i]);

    merge(arr1, arr2, n1, n2);
    return 0;
}

void merge(int *arr1, int *arr2, int n1, int n2)
{
    int n = n1+n2;
    int arr[40];
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    if(i >= n1)
    {
        while(j < n2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    if(j >= n2)
    {
        while(i < n1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }

    printf("After Merge:\n");
    for(k=0; k<n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}