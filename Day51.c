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
struct Node* lcaBST(struct Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data > n1 && root->data > n2) return lcaBST(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return lcaBST(root->right, n1, n2);
    return root;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        root = insertBST(root, val);
    }
    int n1, n2;
    if (scanf("%d %d", &n1, &n2) != 2) return 0;
    struct Node* lca = lcaBST(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}
