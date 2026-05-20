#include <stdio.h>
#include <stdlib.h>

// Day 95 - DSA Challenge: Bucket Sort Algorithm

struct Node {
    float data;
    struct Node* next;
};

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(sizeof(struct Node*) * n);
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (buckets[bi] == NULL) {
            buckets[bi] = newNode;
        } else {
            struct Node* temp = buckets[bi];
            struct Node* prev = NULL;
            while (temp != NULL && temp->data <= arr[i]) {
                prev = temp;
                temp = temp->next;
            }
            if (prev == NULL) {
                newNode->next = buckets[bi];
                buckets[bi] = newNode;
            } else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[index++] = temp->data;
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);
    printf("\n");
    return 0;
}
