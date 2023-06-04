#include <stdio.h>

void reverse(char *, int);

int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);

    int n=0;
    while(str[n] != '\0')
        n++;
    
    reverse(str, n);
    printf("After reverse: %s", str);

    return 0;
}

void reverse(char *str, int n)
{
    int i, temp;
    for(i=0; i<n/2; i++)
    {
        temp = *(str+i);
        *(str+i) = *(str+n-1-i);
        *(str+n-1-i) = temp;
    }
}