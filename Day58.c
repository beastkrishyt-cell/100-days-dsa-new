#include <stdio.h>
#include <stdlib.h>
struct Node { char data; struct Node *left, *right; };
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->left = node->right = NULL;
    return node;
}
int search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}
struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd) {
    static int preIndex = 0;
    if (inStrt > inEnd) return NULL;
    struct Node* tNode = newNode(pre[preIndex++]);
    if (inStrt == inEnd) return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}
void printInorder(struct Node* node) {
    if (!node) return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
int main() {
    char in[100], pre[100];
    if (scanf("%s %s", in, pre) != 2) return 0;
    int len = 0;
    while (in[len] != '\0') len++;
    struct Node* root = buildTree(in, pre, 0, len - 1);
    printInorder(root);
    printf("\n");
    return 0;
}
