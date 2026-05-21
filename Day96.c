#include <stdio.h>
#include <stdlib.h>

// Day 96 - DSA Challenge: Counting Inversions in Array

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long countInversions(int arr[], int n) {
    int* temp = (int*)malloc(sizeof(int) * n);
    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of inversions: %lld\n", countInversions(arr, n));
    return 0;
}
