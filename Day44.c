#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->left = node->right = NULL;
    return node;
}
struct Node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n) {
        struct Node* root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}
void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}
void preorder(struct Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}
void postorder(struct Node* root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    inorder(root); printf("\n");
    preorder(root); printf("\n");
    postorder(root); printf("\n");
    return 0;
}
