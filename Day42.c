#include <stdio.h>
int queue[1000], front = 0, rear = 0;
int stack[1000], top = -1;
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        queue[rear++] = val;
    }
    while (front < rear) stack[++top] = queue[front++];
    front = rear = 0;
    while (top >= 0) queue[rear++] = stack[top--];
    for (int i = front; i < rear; i++) printf("%d ", queue[i]);
    printf("\n");
    return 0;
}
