#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int arr[MAX];
int front = -1;
int rear = -1;

void insert();
void del();
void disp();

int main()
{
    int c;
    while(1)
    {
        printf("Enter the command:\n");
        printf("Insert: 1  Delete: 2  Display: 3  Exit: -1\n");
        scanf("%d", &c);

        switch (c)
        {
        case -1:
            exit(0);
        case 1:
            insert();
            break;
        case 2:
            del();
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

void insert()
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("OVERFLOW\n");
        return;
    }
    if(front == -1)
    {
        front++;
        rear++;
    }
    else if(rear == MAX-1)
        rear = 0;
    else
        rear++;

    printf("Enter the number: ");
    scanf("%d",&arr[rear]);
}

void del()
{
    if(front < 0)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Deleted: %d\n", arr[front]);
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == MAX-1)
        front = 0;
    else
        front++;
}

void disp()
{
    if(front < 0)
    {
        printf("UNDERFLOW\n");
        return;
    }
    printf("Queue:\n");
    int i = front;
    if(front <= rear)
    {
        while(i <= rear)
        {
            printf("%d ", arr[i]);
            i++;
        }
    }
    else
    {
        while(i < MAX)
        {
            printf("%d ", arr[i]);
            i++;
        }
        i = 0;
        while(i <= rear)
        {
            printf("%d ", arr[i]);
            i++;
        }
    }
    printf("\n");
}