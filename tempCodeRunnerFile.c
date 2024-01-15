#include <stdio.h>
#define max 5
int stack[max], top = -1;
void push();
void pop();
void peep();
void change();
void display();

void main()
{
    int choice;
    while (1)
    {
      
        printf("\n1.Push \n2.Pop \n3.Peep \n4.Change \n5.Display \n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3:peep();
            break;
        case 4:change();
            break;
        case 5:display();
            break;
        case 6:exit(0);

        default:
            printf("\nInvaid");
        }
    }
}

void push()
{
    if (top >= max-1)
    {
        printf("stack Overflow");
    }
    else
    {
        int x;
        printf("\nEnter value\n");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Value Insered successfully %d\n",stack[top]);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
          stack[top]= top-1;
         printf("Node Deleted Successfully %d\n",);

    }
}
void peep()
{
    int i;
    printf("Enter Position: \n");
    scanf("%d", &i);
    if ((top - i + 1) <= 0)
    {
        printf("Position not found \n");
    }
    else
    {

        printf("%d", stack[top-i+1]);
    }
}
void change()
{
    int i;
    printf("\nEnter Position\n");
    scanf("%d", &i);
    if ((top - i + 1) <= 0)
    {
        printf("\nPosition not found");
    }
    else
    {
        int x;
        printf("\nEnter value\n");
        scanf("%d", &x);
        stack[top-i+1] = x;


    }
}
void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
