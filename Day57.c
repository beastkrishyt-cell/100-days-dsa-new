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
void mirror(struct Node* node) {
    if (!node) return;
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}
void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    mirror(root);
    inorder(root);
    printf("\n");
    return 0;
}
