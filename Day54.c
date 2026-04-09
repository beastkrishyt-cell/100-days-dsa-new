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
void zigzagOrder(struct Node* root) {
    if (!root) return;
    struct Node* currentLevel[1000];
    struct Node* nextLevel[1000];
    int ctop = -1, ntop = -1;
    int leftToRight = 1;
    currentLevel[++ctop] = root;
    while (ctop >= 0) {
        struct Node* temp = currentLevel[ctop--];
        if (temp) {
            printf("%d ", temp->data);
            if (leftToRight) {
                if (temp->left) nextLevel[++ntop] = temp->left;
                if (temp->right) nextLevel[++ntop] = temp->right;
            } else {
                if (temp->right) nextLevel[++ntop] = temp->right;
                if (temp->left) nextLevel[++ntop] = temp->left;
            }
        }
        if (ctop == -1) {
            leftToRight = 1 - leftToRight;
            while (ntop >= 0) {
                currentLevel[++ctop] = nextLevel[ntop--];
            }
        }
    }
    printf("\n");
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    zigzagOrder(root);
    return 0;
}
