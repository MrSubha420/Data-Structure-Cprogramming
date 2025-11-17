#include <stdio.h>
#include <stdlib.h>

// Node structure for 2-3 tree
typedef struct Node {
    int keys[3];
    struct Node* children[4];
    int numKeys;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    for (int i = 0; i < 4; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to split a 4-node
void split(Node* parent, int index) {
    Node* newNode = createNode(parent->keys[1]);
    newNode->children[0] = parent->children[2];
    newNode->children[1] = parent->children[3];
    parent->numKeys = 1;

    if (index == 0) {
        parent->children[0] = parent->children[1];
        parent->children[1] = newNode;
    } else if (index == 1) {
        parent->children[1] = newNode;
    } else {
        parent->children[2] = parent->children[3];
        parent->children[3] = newNode;
    }
}

// Function to recursively insert a key into the tree
void insertRec(Node* root, int key) {
    if (root == NULL) {
        return;
    }
    
    if (root->numKeys == 3) { // 4-node
        split(root, 1);
        if (key > root->keys[1]) {
            root = root->children[2];
        }
    }
    
    int i = root->numKeys - 1;
    while (i >= 0 && key < root->keys[i]) {
        root->keys[i + 1] = root->keys[i];
        i--;
    }
    root->keys[i + 1] = key;
    root->numKeys++;

    if (root->keys[i + 1] != key) { // Avoid duplicate keys
        return;
    }

    if (root->numKeys == 3 && root->keys[1] == key) { // Duplicate in a 3-node
        split(root, 1);
    }
}

// Function to insert a key into the tree
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    insertRec(root, key);

    if (root->numKeys == 3) { // Root is a 4-node
        Node* newRoot = createNode(root->keys[1]);
        newRoot->children[0] = root;
        newRoot->children[1] = root->children[1];
        newRoot->children[2] = root->children[2];
        root->numKeys = 1;
        root->keys[0] = root->keys[2];
        root->children[1] = root->children[3];
        root->children[2] = NULL;
        return newRoot;
    }
    return root;
}

// Function to print inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->children[0]);
    for (int i = 0; i < root->numKeys; i++) {
        printf("%d ", root->keys[i]);
        inorderTraversal(root->children[i + 1]);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25, 35, 45, 55};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
