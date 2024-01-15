#include<stdio.h>

int main() {
    int a[10], i, size, index, flag = 0, key;
    printf("Enter size:");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &a[i]);
    }

    printf("Enter Key:");
    scanf("%d", &key);

    for (i = 0; i < size; i++) {
        if (key == a[i]) {
            printf("Element Found at index %d \n", i);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Element Not Found");
    }

    return 0;
}
