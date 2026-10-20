// Design and implement a Heap data structure, including its fundamental operations and practical applications.
// Objectives:
// 1.	Understand the concept and properties of a heap.
// 2.	 Implement heap operations such as: 
// o	Insertion
// o	Deletion
// o	Peek/Find maximum or minimum
// o	Heapify
// o	Extract maximum or minimum

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int heap[MAX_SIZE];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapify(largest);
    }
}
void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = value;
    size++;
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);
}
void delete() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}
int peek() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap[0];
}
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    printf("Max element: %d\n", peek());
    delete();
    printf("Max element after deletion: %d\n", peek());
    return 0;
}
