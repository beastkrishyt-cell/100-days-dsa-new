#include <stdio.h>
int deque[1000], front = -1, rear = -1, size = 1000;
void insertFront(int val) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (front == 0) front = size - 1;
    else front--;
    deque[front] = val;
}
void insertLast(int val) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (rear == size - 1) rear = 0;
    else rear++;
    deque[rear] = val;
}
void deleteFront() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (front == size - 1) front = 0;
    else front++;
}
void deleteLast() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = size - 1;
    else rear--;
}
void display() {
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) { int v; scanf("%d", &v); insertFront(v); }
        else if (type == 2) { int v; scanf("%d", &v); insertLast(v); }
        else if (type == 3) deleteFront();
        else if (type == 4) deleteLast();
        else if (type == 5) display();
    }
    return 0;
}
