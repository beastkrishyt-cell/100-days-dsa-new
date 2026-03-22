#include <stdio.h>
int queue[1000], front = -1, rear = -1, size = 1000;
void enqueue(int val) {
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) return;
    else if (front == -1) front = rear = 0;
    else if (rear == size - 1 && front != 0) rear = 0;
    else rear++;
    queue[rear] = val;
}
void dequeue() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (front == size - 1) front = 0;
    else front++;
}
void display() {
    if (front == -1) return;
    if (rear >= front) {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    } else {
        for (int i = front; i < size; i++) printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++) printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int val; scanf("%d", &val);
            enqueue(val);
        } else if (type == 2) { dequeue(); }
        else if (type == 3) { display(); }
    }
    return 0;
}
