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
void rightViewUtil(struct Node* root, int level, int *max_level) {
    if (!root) return;
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
void rightView(struct Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
    printf("\n");
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    rightView(root);
    return 0;
}
// update 1
// update 1
// update 1
// update 1
// update 1
// update 1
// update 1
