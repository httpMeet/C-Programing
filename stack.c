#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX],top = -1;

void push();
void pop();
void peep();
void display();

int main()
{
    int ch;
    while (1)
    {
        printf("\n 1.PUSH\n 2.POP\n 3.PEEP\n 4.Display\n 5.Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid");
        }
    }
    return 0; // Return 0 to indicate successful execution
}

void push()
{

    if (top >= MAX - 1)
    {
        printf("Stack Overflow \n");
        return;
    }
    int x;
    printf("Enter value:");
    scanf("%d", &x);
    top = top + 1;
    stack[top] = x;
    printf("inserted:%d \n", x);
}

void pop()
{
    int x;
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    x = stack[top];
    top = top - 1;
    printf("Deleted:%d\n",x);
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

void peep()
{

    int index;
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Enter index:");
    scanf("%d", &index);
    if (index < 0 || index > top)
    {
        printf("Invalid index\n");
        return;
    }
    printf("Peep:%d\n", stack[top - index + 1]);
}
void change(){
}
