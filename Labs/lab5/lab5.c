#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build tree recursively with user input
struct Node* buildTree() {
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct Node* root = createNode(value);

    printf("Enter left child of %d\n", value);
    root->left = buildTree();

    printf("Enter right child of %d\n", value);
    root->right = buildTree();

    return root;
}

// Pre-order traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// In-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Post-order traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();

    printf("\nPre-order traversal: ");
    preorder(root);

    printf("\nIn-order traversal: ");
    inorder(root);

    printf("\nPost-order traversal: ");
    postorder(root);

    return 0;
}
