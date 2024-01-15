#include<stdio.h>

int main() {
    int a[10], i, size, index, flag = 0, key, beg = 0, end, mid;
    printf("Enter size:");
    scanf("%d", &size);
    end = size - 1;

    for (i = 0; i < size; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &a[i]);
    }

    printf("Enter Key:");
    scanf("%d", &key);

    while (beg <= end) {
        mid = (beg + end) / 2;
        if (key == a[mid]) {
            printf("Element Found at a[%d]", mid);
            flag = 1;
            break;
        } else if (key > a[mid]) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (flag == 0) {
        printf("Element Not Found");
    }

    return 0;
}
