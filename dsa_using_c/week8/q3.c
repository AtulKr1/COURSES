#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Stack
{
    int data;
    struct Stack *next;
}*top = NULL;

typedef struct Stack node;

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
    if(top == NULL)
        top = temp;

    else
    {
        temp -> next = top;
        top = temp;
    }
    
}

void pop()
{
    if(top == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }

    node *temp = top;
    printf("POPPED: %d\n", top -> data);
    top = top -> next;
    free(temp);
}

void disp()
{
    node *ptr = top;
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