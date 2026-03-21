#include <stdio.h>
int queue[1000], front = -1, rear = -1;
void enqueue(int val) {
    if (front == -1) front = 0;
    queue[++rear] = val;
}
void dequeue() {
    if (front != -1 && front <= rear) front++;
    if (front > rear) front = rear = -1;
}
void display() {
    for (int i = front; i != -1 && i <= rear; i++) printf("%d ", queue[i]);
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
