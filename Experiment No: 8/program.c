#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node dynamically
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree/subtree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Insert into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Insert into the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Duplicate values are ignored
    return root;
}

// Inorder Traversal: Left, Root, Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal: Root, Left, Right
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal: Left, Right, Root
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Driver code
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Display the traversals
    printf("Inorder traversal (sorted): ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal:         ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal:        ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
