#include <stdio.h>
#include <stdlib.h>

int c = 0;

void merge(int arr[], int left[], int leftsize, int right[], int rightsize) {
    int i = 0, j = 0, k = 0;

    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            c += leftsize - i;
        }
    }

    while (i < leftsize)
        arr[k++] = left[i++];

    while (j < rightsize)
        arr[k++] = right[j++];
}

void mergesort(int arr[], int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    mergesort(left, mid);
    mergesort(right, size - mid);

    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

int main() {
    int n, y;
    while (1) {
        printf("\nEnter 1 to start / 0 to exit: ");
        scanf("%d", &y);
        if (y == 1) {
            printf("Enter the size of the list: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Invalid size. Please enter a positive integer.\n");
                continue;
            }

            int *arr = (int *)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed. Exiting.\n");
                exit(1);
            }

            for (int i = 0; i < n; i++) {
                printf("Enter the number %d: ", i);
                scanf("%d", &arr[i]);
            }
            c = 0;
            mergesort(arr, n);

            printf("\nSorted List: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i);

            printf("\nNumber of inversions: %d\n");

            free(arr);
        } else if (y == 0) {
            exit(0);
        } else {
            printf("Invalid choice. Please enter 1 to start or 0 to exit.\n");
        }
    }
    return 0;
}

