#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head) { head = tail = newNode; }
        else { tail->next = newNode; tail = newNode; }
    }
    int key, count = 0;
    if (scanf("%d", &key) != 1) return 0;
    struct Node* temp = head;
    while (temp) {
        if (temp->data == key) count++;
        temp = temp->next;
    }
    printf("%d\n", count);
    return 0;
}
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
