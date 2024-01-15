#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define max 5
int queue[max];
int front = -1;
int rear = -1;

void insert();
void del();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\n---------------\n");
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\n---------------\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvaid");
        }
    }
}

void insert()
{
    if (rear >= max)
    {
        printf("\nOverflow");
        return;
    }
    else
    {
        int x;
        printf("\nEnter the value\n");
        scanf("%d", &x);
        rear = rear + 1;
        queue[rear] = x;
        if (front == -1)
        {
            front = 0;
            return;
        }
        
    }
}

void del()
{
    if (front == -1)
    {
        printf("\nUnderflow");
        return;
    }
    else
    {
        if (front == rear)
        {
            printf("\ndeleted element id %d", queue[front]);
            front = -1;
            rear = -1;
        }
        else
        {
            printf("\ndeleted element id %d", queue[front]);
            front++;
        }
    }
}

void display()
{
    printf("\n---------------\n");
    for (int i = rear; i >= front; i--)
    {
        printf("%d\n", queue[i]);
    }
    printf("\n---------------\n");
}