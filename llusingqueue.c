#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(int value);
void delete();
void display();

int main() {
    int choice, value;
    while (1) {
        printf("Enter\n 1. for insert \n 2. for delete \n 3. for display\n 4. for exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
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

void insert(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Successfully inserted\n");
}

void delete() {
    if (front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        struct node *temp = front;
        printf("\nDeleted element: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = front;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
