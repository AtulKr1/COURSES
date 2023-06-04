#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int arr[MAX];
int start = -1;
int cur = -1;

void push();
void pop();
void disp();

int main()
{
    int c;
    while(1)
    {
        printf("Enter the command:\n");
        printf("Push: 1\tPop: 2\tDisplay: 3\tExit: -1\n");
        scanf("%d", &c);

        switch (c)
        {
        case -1:
            exit(0);
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        default:
            printf("Enter Again\n");
        }
    }
    return 0;
}

void push()
{
    if(cur >= MAX-1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if(start == -1)
        start++;
    cur++;
    printf("Enter the number: ");
    scanf("%d",&arr[cur]);
}

void pop()
{
    if(cur < 0 || start > cur)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("POPPED: %d\n", arr[start]);
    start++;
}

void disp()
{
    if(cur < 0 || start > cur)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Queue:\n");
    int i;
    for(i=start; i<=cur; i++)
        printf("%d ", arr[i]);
    printf("\n");
}