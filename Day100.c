#include <stdio.h>
#include <stdlib.h>

// Day 100 - DSA Challenge: Count of Smaller Numbers After Self

struct Element {
    int value;
    int originalIndex;
};

void merge(struct Element arr[], int count[], int left, int mid, int right) {
    struct Element* temp = (struct Element*)malloc(sizeof(struct Element) * (right - left + 1));
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].originalIndex] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].originalIndex] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
    free(temp);
}

void mergeSort(struct Element arr[], int count[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, count, left, mid);
    mergeSort(arr, count, mid + 1, right);
    merge(arr, count, left, mid, right);
}

void countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* count = (int*)calloc(numsSize, sizeof(int));
    struct Element* arr = (struct Element*)malloc(sizeof(struct Element) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].originalIndex = i;
    }

    mergeSort(arr, count, 0, numsSize - 1);
    
    printf("Counts array: ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(arr);
    free(count);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    printf("Input Array: 5 2 6 1\n");
    countSmaller(nums, n, &returnSize);

    return 0;
}
