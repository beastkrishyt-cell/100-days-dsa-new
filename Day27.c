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
    struct Node* t1 = l1;
    int found = 0;
    while (t1) {
        struct Node* t2 = l2;
        while (t2) {
            if (t1->data == t2->data) {
                printf("%d\n", t1->data);
                found = 1;
                break;
            }
            t2 = t2->next;
        }
        if (found) break;
        t1 = t1->next;
    }
    if (!found) printf("No Intersection\n");
    return 0;
}
