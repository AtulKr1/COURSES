#include <stdio.h>

void armstrong(int);
void pali(int);

int main()
{
    int n;
    
    printf("Enter a 3 digit number: ");
    scanf("%d", &n);
    armstrong(n);

    printf("Enter a 4 digit number: ");
    scanf("%d", &n);
    pali(n);

    return 0;
}

void armstrong(int n)
{
    int cpy = n;
    int new_no = 0;
    int t;

    while(cpy>0)
    {
        t = cpy%10;
        new_no += t*t*t;
        cpy /= 10;
    }
    if(new_no == n)
        printf("Number is armstrong.\n");
    else
        printf("Number is not armstorong.\n");
}

void pali(int n)
{
    int cpy = n;
    int new_no = 0;

    while(cpy>0)
    {
        new_no *= 10;
        new_no += cpy%10;
        cpy /= 10;
    }
    if(new_no == n)
        printf("Number is palindrome.\n");
    else
        printf("Number is not a palindrome.\n");
}