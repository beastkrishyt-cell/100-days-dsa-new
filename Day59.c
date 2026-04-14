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
struct Node* buildUtil(char in[], char post[], int inStrt, int inEnd, int *pIndex) {
    if (inStrt > inEnd) return NULL;
    struct Node* node = newNode(post[*pIndex]);
    (*pIndex)--;
    if (inStrt == inEnd) return node;
    int iIndex = search(in, inStrt, inEnd, node->data);
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
    return node;
}
struct Node* buildTree(char in[], char post[], int n) {
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}
void printInorder(struct Node* node) {
    if (!node) return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
int main() {
    char in[100], post[100];
    if (scanf("%s %s", in, post) != 2) return 0;
    int n = 0;
    while (in[n] != '\0') n++;
    struct Node* root = buildTree(in, post, n);
    printInorder(root);
    printf("\n");
    return 0;
}
