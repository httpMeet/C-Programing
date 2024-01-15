#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push();
void pop();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("Enter\n 1. for push\n 2. for pop\n 3. for display\n 4. for exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
}

void push()
{
    struct node *newnode;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);
    newnode->data = value;
    if (top == NULL)
    {
        newnode->link = NULL;
    }
    else
    {
        newnode->link = top;
    }
    top = newnode;
    printf("Successfully inserted\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        printf("\nDeleted element: %d\n", temp->data);
        top = temp->link;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}
