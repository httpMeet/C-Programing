#include <stdio.h>
#include <stdlib.h>

#define max 5

int a[max];
int front = -1;
int rear = -1;
int flag = 0;

void insert();
void del();
void display();

int main() {
    int ch;

    while (1) {
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
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
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}

void insert() {
    if((rear == max - 1 && front == 0) || (front == rear + 1)) {
        printf("\nOverflow: Queue is full");
    } else {
        int value;
        printf("\nEnter the value: ");
        scanf("%d", &value);

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if ((rear == max - 1) && front > 0) {
            rear = 0;
        } else {
            rear++;
        }

        a[rear] = value;
        printf("Inserted Value Is %d\n", a[rear]);
        flag = 1;
    }
}
void del() {
    if (front == -1){
        printf("\n Underflow: Queue is empty ");
    } else {
        printf("\n Deleted element id %d", a[front]);

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == max - 1){
            front = 0;
        } else {
            front++;
        }
    }
}

void display(){
    if (flag == 0){
        printf("Nothing has been inserted yet....\n");
    } 
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", a[i]);
        }
    }
}
