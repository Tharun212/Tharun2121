#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low, int high) {
    int pivot, i, j;
    pivot = a[low];
    i = low;
    j = high;

    while (i < j) {
        do {
            i++;
        } while (a[i] <pivot);

        do {
            j--;
        } while (a[j] >pivot);

        if (i < j) {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j);
        quicksort(a, j + 1, high);
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Original array: ");
    print(a, n);
    quicksort(a, 0, n - 1);
    printf("Sorted array: ");
    print(a, n);

    return 0;
}

