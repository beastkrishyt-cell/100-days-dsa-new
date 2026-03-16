#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int c, e; scanf("%d %d", &c, &e);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;
        if (!head) { head = tail = newNode; }
        else { tail->next = newNode; tail = newNode; }
    }
    struct Node* temp = head;
    while (temp) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp) printf(" + ");
    }
    printf("\n");
    return 0;
}
