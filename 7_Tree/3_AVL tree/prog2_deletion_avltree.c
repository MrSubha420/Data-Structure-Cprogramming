#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
    // Find the correct position to insert the node and insert it
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Perform rotations if needed
    if (balance > 1 && key < node->left->key) // LL rotation
        return rightRotate(node);
    if (balance < -1 && key > node->right->key) // RR rotation
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) // LR = RR + LL
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) // RL = LL + RR
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
struct Node *deleteNode(struct Node *root, int key) {
    // Find the node and delete it
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if needed
    if (balance > 1 && getBalance(root->left) >= 0) // LL
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) // LR = RR + LL
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) // RR
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) // RL = LL + RR
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print AVL tree
void printTree(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->key);

    printTree(root->left, space);
}

int main() {
    struct Node *root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,20);
    root = insertNode(root,24);
    root = insertNode(root,10);
    root = insertNode(root,13);
    root = insertNode(root,7);
    root = insertNode(root,30);

    printf("Original AVL Tree:\n");
    printTree(root, 0);

    // Example: Deleting nodes from AVL tree
    root = deleteNode(root, 24);
    root = deleteNode(root, 20);
    //root = deleteNode(root, 8);

    printf("AVL Tree after deletions:\n");
    printTree(root, 0);

    return 0;
}
