#include <stdio.h>

int is_prime(int);
int fact(int);
void fabi(int);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Factorial of %d = %d\n", n, fact(n));

    if(is_prime(n))
        printf("Number is prime.\n");
    else
        printf("Number is not a prime.\n");
    
    fabi(n);

    return 0;
}

int fact(int n)
{
    int i;
    int f = 1;
    for(i=1; i<=n; i++)
    {
        f *= i;
    }
    return f;
}

int is_prime(int n)
{
    if(n == 1)
        return 0;

    int i;
    for(i=2; i<=n/2; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

void fabi(int n)
{
    int a=0, b=1, temp;
    if(n == 1)
        printf("0\n");
    else
    {
        printf("0 1 ");
        n -= 2;
        
        while(n)
        {
            temp = a+b;
            a = b;
            b = temp;
            printf("%d ", b);
            n--;
        }
    }
}