#include <stdio.h>
#include <stdlib.h>

#define max 5
void insert();
void delete();
void display();

int front = -1, rear = -1;
int q[max];

void main() {
    int choice;

    while (1) {
        printf("\n1. Insert an element\n2. Delete an element\n3. Display the Queue \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter valid choice.\n");
        }
    }
}

void insert() {
    int item;

    printf("Enter the element: ");
    scanf("%d", &item);

    if (rear >= max) {
        printf("Queue Overflow\n");
        return;
    } else {
        rear++;
        q[rear] = item;
        printf("Inserted: %d\n", q[rear]);
    }

    if (front == -1) {
        front = 0;
    }
}

void delete() {
    int item;

    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    item = q[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    printf("Value deleted: %d\n", item);
}

void display() {
    int i;

    if (rear == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Inserted Values are: ");
        for (i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    }
}
