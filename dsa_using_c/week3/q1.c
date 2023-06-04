#include<stdio.h>
#define N 3

void enter(int [N][N]);
void print(int [N][N]);
void add(int [N][N], int [N][N]);
void mult(int [N][N], int [N][N]);
void trans(int [N][N]);

int main()
{
    int m1[N][N], m2[N][N];

    printf("Enter the matrix 1:\n");
    enter(m1);
    printf("Enter the matrix 2:\n");
    enter(m2);

    add(m1, m2);
    mult(m1, m2);
    trans(m1);

    return 0;
}

void enter(int m[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            scanf("%d", &m[i][j]);
    }
}

void print(int m[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void add(int a[N][N], int b[N][N])
{
    int i, j;
    int ans[N][N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            ans[i][j] = a[i][j]+b[i][j];
    }

    printf("Sum of matrices:\n");
    print(ans);
}

void mult(int a[][N], int b[][N])
{
    int i, j, k;
    int ans[N][N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            ans[i][j] = 0;
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            for(k=0; k<N; k++)
                ans[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Matrix multiplication:\n");
    print(ans);
}

void trans(int a[N][N])
{
    int i, j;
    int ans[N][N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            ans[i][j] = a[j][i];
        }
    }

    printf("Transpose of matrix:\n");
    print(ans);
}