#include <stdio.h>

void merge(int arr[], int beg, int mid, int end) {
    int i = beg;
    int j = mid + 1;
    int index =  beg;
    int temp[20];
    int k;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[index] = arr[i];
            i = i + 1;
        } else {
            temp[index] = arr[j];
            j = j + 1;
        }
        index = index + 1;
    }

    if (i > mid) {
        while (j <= end) {
            temp[index] = arr[j];
            index = index + 1;
            j = j + 1;
        }
    } else {
        while (i <= mid) {
            temp[index] = arr[i];
            i = i + 1;
            index = index + 1;
        }
    }

    for (k = beg; k < index; k++) {
        arr[k] = temp[k];
    }
}

void mergeSort(int arr[], int beg, int end) {
    int mid;
    if (beg < end) {
        mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int a[20], i, n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
