#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct linked_list
{
    int data;
    struct linked_list *next;
}*start = NULL, *ptr = NULL;

typedef struct linked_list node;

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
    printf("Enter data and position respectively: ");
    int x, pos;
    scanf("%d%d", &x, &pos);

    node *temp = (node *)malloc(sizeof(node));
    temp -> data = x;
    temp -> next = NULL;
    if(start == NULL)
        start = temp;
    else if(pos == 1)
    {
        temp -> next = start;
        start = temp;
    }
    else if(pos > n)
    {
        ptr = start;
        while(ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = temp;
    }
    else
    {
        int i = 1;
        ptr = start;
        while(i < pos - 1)
        {
            ptr = ptr -> next;
            i++;
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
    n++;
}

void pop()
{
    if(n == 0)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Enter the position to pop: ");
    int pos;
    scanf("%d", &pos);

    if(pos == 1)
    {
        ptr = start;
        start = start -> next;
        free(ptr);
    }
    else if(pos >= n)
    {
        ptr = start;
        node *temp;
        while(ptr -> next != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = NULL;
        free(ptr);
    }
    else
    {
        int i = 1;
        ptr = start;
        while(i < pos - 1)
        {
            ptr = ptr -> next;
            i++;
        }
        node *temp = ptr -> next;
        ptr -> next = temp -> next;
        free(temp);
    }
    n--;
}

void disp()
{
    if(n == 0)
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}