#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    if (n == 0) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head) { head = tail = newNode; }
        else { tail->next = newNode; tail = newNode; }
    }
    k = k % n;
    if (k > 0) {
        tail->next = head;
        int steps = n - k;
        struct Node* newTail = tail;
        while (steps--) {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = NULL;
    }
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
