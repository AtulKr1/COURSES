#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct double_linked_list
{
    int data;
    struct double_linked_list *next;
    struct double_linked_list *prev;
}*start = NULL, *ptr = NULL, *end = NULL;

typedef struct double_linked_list node;

void push();
void pop();
void disp_prev();
void disp_next();
int n = 0;

int main()
{
    int c;
    while(1)
    {
        printf("Enter the command:\n");
        printf("Push: 1  Pop: 2  Display_next: 3  Display_prev: 4  Exit: -1\n");
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
            disp_next();
            break;
        case 4:
            disp_prev();
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
    temp -> prev = NULL;
    if(start == NULL)
    {
        start = temp;
        end = temp;
    }
    else if(pos == 1)
    {
        temp -> next = start;
        start -> prev = temp;
        start = temp;
    }
    else if(pos > n)
    {
        ptr = start;
        while(ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = temp;
        temp -> prev = ptr;
        end = temp;
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
        node *temp2 = ptr -> next;
        ptr -> next = temp;
        temp -> prev = ptr;
        temp -> next = temp2;
        temp2 -> prev = temp;
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
    printf("Enter the position from start to pop: ");
    int pos;
    scanf("%d", &pos);

    if(pos == 1)
    {
        ptr = start;
        start = start -> next;
        start -> prev = NULL;
        free(ptr);
    }
    else if(pos >= n)
    {
        ptr = end;
        end = end -> prev;
        end -> next = NULL;
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
        temp -> next -> prev = ptr;
        ptr -> next = temp -> next;
        free(temp);
    }
    n--;
}

void disp_next()
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

void disp_prev()
{
    if(n == 0)
    {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = end;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("\n");
}