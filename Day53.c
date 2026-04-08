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
void getMinMax(struct Node* node, int hd, int *min, int *max) {
    if (!node) return;
    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;
    getMinMax(node->left, hd - 1, min, max);
    getMinMax(node->right, hd + 1, min, max);
}
void printVerticalLine(struct Node* node, int line_no, int hd) {
    if (!node) return;
    if (hd == line_no) printf("%d ", node->data);
    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}
void verticalOrder(struct Node* root) {
    if (!root) return;
    int min = 0, max = 0;
    getMinMax(root, 0, &min, &max);
    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    verticalOrder(root);
    return 0;
}
