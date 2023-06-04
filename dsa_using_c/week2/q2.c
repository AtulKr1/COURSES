#include<stdio.h>

void reverse(char *, int);
void count(char *, int);

int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);
    int n = 0;
    while(str[n] != '\0')
    {
        n++;
    }
    
    reverse(str, n);
    count(str, n);

    return 0;
}

void reverse(char *str, int n)
{
    int i, temp;

    for(i=0; i<n/2; i++)
    {
        temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }

    printf("After Swap: %s\n", str);
}

void count(char *str, int n)
{
    char vowel[10] = "AEIOUaeiou";
    int nvowel=0;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<10; j++)
        {
            if(str[i] == vowel[j])
            {
                nvowel++;
                break;
            }
        }
    }
    
    printf("Number of Vowels = %d\n", nvowel);
    printf("Number of Consonants = %d\n", n-nvowel);
}