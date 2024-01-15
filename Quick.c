#include <stdio.h>
void Swap(int *a, int *b);
int Partition(int arr[], int beg, int end);
void QuickSort(int arr[], int beg, int end);

int main() {
    int a[20], i, n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}


void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int beg, int end) {
    int pivot = arr[beg];
    int i = beg + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && arr[i] <= pivot) {
            i++;
        }
        while (j > beg && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            Swap(&arr[i], &arr[j]);
        }
    }

    Swap(&arr[beg], &arr[j]);
    return j;
}

void QuickSort(int arr[], int beg, int end) {
    if (beg < end) {
        int pivot = Partition(arr, beg, end);
        QuickSort(arr, beg, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
