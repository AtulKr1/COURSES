#include<stdio.h>
#define MAX 10

void swap(int *, int *);
void out(int *, int);
void insert(int *, int);

int main()
{
    int n, i;
    printf("Enter the size of array; ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    insert(arr, n);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void out(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int *arr, int n)
{
    if(n >= MAX)
    {
        printf("OVERFLOW\n");
        return;
    }

    int k, num;
    printf("Enter the new element and position respectively:\n");
    scanf("%d%d", &num, &k);

    if(k > n)
        k = n;
    n++;
    int temp = num;
    int i;
    for(i=k; i<n; i++)
        swap(&arr[i], &temp);

    printf("After Insert:\n");
    out(arr, n);
}