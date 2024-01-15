#include <stdio.h>

int main() {
    int a[20], i, j, n, mid, temp;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }
 
    for (i = 0; i < n - 1; i++) {
        mid = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] < a[mid]) {
                mid = j;
            }
        }
            
            temp = a[i];
            a[i] = a[mid];
            a[mid] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
