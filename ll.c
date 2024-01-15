#include<stdio.h>  
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *first;
void begininsert();
void lastinsert();
void sortedinsert();
void deletebeg();
void deleteend();
void midinsert();
void display();
int main(){
    int choice;
    while (1){
        printf("\n 1.Insert at Begin \n 2.Insert at Last \n 3.Insert at sorted Manner \n 4.Delete at begin \n 5.Delete at End \n 6.Display \n 7.Insert at Middle \n 8.exit \n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: begininsert();
                break;
            case 2: lastinsert();
                break;
            case 3: sortedinsert();
                break;
            case 4: deletebeg();
                break;
            case 5: deleteend();
                break;
            case 6: display();
                break;
            case 7: midinsert();
                break;
            case 8: exit(0);
                break;
            default: printf("Enter Valid Choice..");
                break;
        }
    }
}
void begininsert() {
    struct node *newnode;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Insufficient Memory");
    } else {
        printf("Enter Value: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->link = first;
        first = newnode;
        printf("Node Inserted");
    }
}
void deletebeg(){
    struct node *ptr;
    if (first == NULL) {
        printf("\n List is Empty");
    } else {
        ptr = first;
        first = ptr->link;
        free(ptr);
        printf("Node Delete From begin");
    }
}
void lastinsert() {
    struct node *newnode, *save;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Insufficient Memory");
    } else {
        printf("\n Enter Value: ");
        scanf("%d", &value);
        newnode->data = value;
        if (first == NULL) {
            newnode->link = NULL;
            first = newnode;
            printf("Node Inserted \n");
        } else {
            save = first;
            while (save->link != NULL) {
                save = save->link;
            }
            save->link = newnode;
            newnode->link = NULL;
            printf("Node Inserted \n");
        }
    }
}

void deleteend() {
    struct node *save, *ptr;
    if (first == NULL) {
        printf("List is Empty");
    } else if (first->link == NULL) {
        first = NULL;
        free(first);
        printf("Only Node of the List is Deleted \n");
    } else {
        ptr = first;
        while (ptr->link != NULL) {
            save = ptr;
            ptr = ptr->link;
        }
        save->link = NULL;
        free(ptr);
        printf("Node deleted From end");
    }
}
void midinsert() {
    struct node *newnode, *ptr, *save;
    int value, n, i;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Insufficient Memory");
    } else {
        printf("Enter Location: ");
        scanf("%d", &n);
        printf("Enter Value: ");
        scanf("%d", &value);

        newnode->data = value;
        ptr = first;

        for (i = 1; i < n; i++) {
            save = ptr;
            ptr = ptr->link;

            if (ptr == NULL) {
                printf("Invalid Location\n");
                return;
            }
        }

        save->link = newnode;
        newnode->link = ptr;
        printf("Node Inserted at middle\n");
    }
}

void sortedinsert() {
    struct node *newnode, *ptr, *save;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Insufficient Memory");
    } else {
        printf("Enter Value: ");
        scanf("%d", &value);

        newnode->data = value;
        ptr = first;
        save = NULL;

        while (ptr != NULL && value > ptr->data) {
            save = ptr;
            ptr = ptr->link;
        }

        if (save == NULL) {
            newnode->link = first;
            first = newnode;
        } else {
            save->link = newnode;
            newnode->link = ptr;
        }

        printf("Node Inserted in sorted manner\n");
    }
}
void display() {
    struct node *ptr;
    ptr = first;
    if (ptr == NULL) {
        printf("Nothing You have Inserted");
    } else {
        printf("Inserted Values are: \n");
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}
