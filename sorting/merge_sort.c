#include <stdio.h>
void merge(int a[], int start, int mid, int end) {
    int i = 0, j = 0, k = start;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = a[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = a[mid + 1 + j]; 
    }

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    printf("enter the elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("before sorting:");
    print(a, n);
    mergesort(a, 0, n - 1);
    printf("After sorting:");
    print(a, n);
    return 0;
}

