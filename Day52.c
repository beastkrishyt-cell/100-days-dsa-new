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
struct Node* lcaBinaryTree(struct Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left_lca = lcaBinaryTree(root->left, n1, n2);
    struct Node* right_lca = lcaBinaryTree(root->right, n1, n2);
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    int n1, n2;
    if (scanf("%d %d", &n1, &n2) != 2) return 0;
    struct Node* lca = lcaBinaryTree(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}
