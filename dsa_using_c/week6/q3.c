#include<stdio.h>

void del(int *, int, int*);
void out(int *, int);

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
    printf("Enter the key to delete:\n");
    scanf("%d", &k);

    del(arr, k, &n);

    return 0;
}

void del(int *arr, int k, int *n)
{
    int i, j;
    for(i=0; i<*n; i++)
    {
        if(arr[i] == k)
        {
            for(j=i+1; j<*n; j++)
                arr[j-1] = arr[j];
            break;
        }
    }
    *n = *n - 1;

    printf("After Deletion:\n");
    out(arr, *n);
}

void out(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}