#include<stdio.h>

int main() {
    int a[10], size, i, j, temp;

    printf("Enter Size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter Element a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf(" Bubble Sorted Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
