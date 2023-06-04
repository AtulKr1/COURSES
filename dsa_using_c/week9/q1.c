#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Queue
{
    int data;
    struct Queue *next;
}*start = NULL, *cur = NULL;

typedef struct Queue node;

void push();
void pop();
void disp();
int n = 0;

int main()
{
    int c;
    while(1)
    {
        printf("Enter the command:\n");
        printf("Push: 1  Pop: 2  Display: 3  Exit: -1\n");
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
    printf("Enter data: ");
    int x;
    scanf("%d", &x);

    node *temp = (node *)malloc(sizeof(node));
    temp -> data = x;
    temp -> next = NULL;
    if(start == NULL)
    {
        start = temp;
        cur = temp;
    }
    else
    {
        cur -> next = temp;
        cur = temp;
    }
}

void pop()
{
    if(cur == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }

    node *temp = start;
    printf("POPPED: %d\n", start -> data);
    start = start -> next;
    free(temp);
}

void disp()
{
    node *ptr = start;
    if(ptr == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}