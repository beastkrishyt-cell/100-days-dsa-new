#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
int main() {
    int n1, n2;
    if (scanf("%d", &n1) != 1) return 0;
    struct Node* l1 = NULL;
    for (int i = 0; i < n1; i++) {
        int val; scanf("%d", &val);
        l1 = insert(l1, val);
    }
    if (scanf("%d", &n2) != 1) return 0;
    struct Node* l2 = NULL;
    for (int i = 0; i < n2; i++) {
        int val; scanf("%d", &val);
        l2 = insert(l2, val);
    }
    struct Node dummy;
    dummy.next = NULL;
    struct Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->data < l2->data) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;
    struct Node* temp = dummy.next;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
