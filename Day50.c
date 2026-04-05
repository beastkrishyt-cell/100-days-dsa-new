#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->left = node->right = NULL;
    return node;
}
struct Node* insertBST(struct Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else if (val > root->data) root->right = insertBST(root->right, val);
    return root;
}
int searchBST(struct Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        root = insertBST(root, val);
    }
    int key;
    if (scanf("%d", &key) != 1) return 0;
    if (searchBST(root, key)) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
