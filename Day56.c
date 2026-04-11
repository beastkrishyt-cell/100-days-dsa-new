#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->left = node->right = NULL;
    return node;
}
struct Node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n && arr[i] != -1) {
        struct Node* root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}
int isMirror(struct Node* node1, struct Node* node2) {
    if (!node1 && !node2) return 1;
    if (node1 && node2 && node1->data == node2->data)
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    return 0;
}
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    if (isSymmetric(root)) printf("Symmetric\n");
    else printf("Not Symmetric\n");
    return 0;
}
