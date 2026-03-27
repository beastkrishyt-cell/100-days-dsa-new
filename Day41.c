#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val; temp->next = NULL;
    if (rear == NULL) { front = rear = temp; return; }
    rear->next = temp; rear = temp;
}
void dequeue() {
    if (front == NULL) return;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}
void display() {
    struct Node* temp = front;
    while (temp) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}
int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) { int v; scanf("%d", &v); enqueue(v); }
        else if (type == 2) dequeue();
        else if (type == 3) display();
    }
    return 0;
}
