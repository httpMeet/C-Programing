#include <stdio.h>
#define MAX 5

int top = -1;
int stack[MAX];
int choice;


void push();
void pop();
void peep();
void change();
void display();



void push() {
    if (top >= MAX) {
        printf("Overflow \n");
    } else {
        int value;
        printf("Enter Value: \n");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Inserted Value is: %d\n", value);
    }
}

void pop() {
    int x;
    if (top == -1) {
        printf("Underflow");
        return;
    } else {
        x = stack[top];
        top--;
        printf("Deleted Element: %d\n", x);
    }
}

void peep() {
    int i;
    printf("Enter the Index Number: \n");
    scanf("%d", &i);
    if((top - i + 1) <= 0) {
        printf("Stack Underflow on Peep \n");
    } else {
        printf("Peep: %d\n", stack[top - i + 1]);
    }
}

void change() {
    int i;
    printf("Enter the Index Number: \n");
    scanf("%d", &i);

    if ((top - i + 1) <= 0) {
        printf("Stack Underflow on Change \n");
    } else {
        int value;
        printf("Enter New Value: ");
        scanf("%d", &value);

        stack[top - i + 1] = value;
        printf("Change value is: %d\n", value);
    }
}


void display() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("\n 1. Push \n 2. Pop \n 3. Peep \n 4. Change \n 5. Display \n");
        printf("Enter Choice \n");
        scanf("%d", &choice);

        switch (choice) {
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
                change();
                break;
            case 5:
                display();
                break;
            default:
                printf("Enter Valid Choice \n");
        }
    }

    return 0;
}
