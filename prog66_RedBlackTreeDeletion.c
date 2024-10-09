#include <stdio.h>
#include <stdlib.h>

// Node structure for Red-Black Tree
struct Node {
    int data;
    struct Node *parent, *left, *right;
    int color;  // 0 for black, 1 for red
};

// Constants for colors
#define RED 1
#define BLACK 0

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->color = RED; // New nodes are always red
    return newNode;
}

// Function to perform left rotation
void leftRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(struct Node **root, struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Function to fix Red-Black Tree violations after insertion
void fixInsert(struct Node **root, struct Node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;  // Flip colors
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;  // Flip colors
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            struct Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;  // Flip colors
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;  // Flip colors
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }

    (*root)->color = BLACK;  // Root always black
}

// Function to fix Red-Black Tree violations after deletion
void fixDelete(struct Node **root, struct Node *x, struct Node *xParent) {
    struct Node *w;
    while (x != *root && (x == NULL || x->color == BLACK)) {
        if (x == xParent->left) {
            w = xParent->right;
            if (w->color == RED) {
                w->color = BLACK;
                xParent->color = RED;
                leftRotate(root, xParent);
                w = xParent->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) &&
                (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = xParent;
                xParent = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = xParent->right;
                }
                w->color = xParent->color;
                xParent->color = BLACK;
                if (w->right != NULL)
                    w->right->color = BLACK;
                leftRotate(root, xParent);
                x = *root;  // Exit the loop
            }
        } else {
            w = xParent->left;
            // Symmetric case for right child (mirrored)
            // Implementation is similar to the left child case
        }
    }
    if (x != NULL)
        x->color = BLACK;
}

// Function to find the minimum value node in a subtree
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to perform the actual deletion of a node
void deleteNode(struct Node **root, struct Node *z) {
    struct Node *y = z;
    struct Node *x, *xParent;

    int yOriginalColor = y->color;
    if (z->left == NULL) {
        x = z->right;
        xParent = z->parent;
        transplant(root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        xParent = z->parent;
        transplant(root, z, z->left);
    } else {
        y = findMin(z->right);
        yOriginalColor = y->color;
        x = y->right;
        xParent = y;
        if (y->parent == z)
            xParent = y;
        else {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);

    if (yOriginalColor == BLACK)
        fixDelete(root, x, xParent);
}

// Function to transplant a subtree in a Red-Black Tree
void transplant(struct Node **root, struct Node *u, struct Node *v) {
    if (u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

// Function to insert a node in Red-Black Tree
void insert(struct Node **root, int data) {
    // Regular BST insert
    struct Node *z = createNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    // Fix Red-Black Tree violations
    fixInsert(root, z);
}

// Function to delete a node in Red-Black Tree
void delete(struct Node **root, int data) {
    struct Node *z = *root;
    while (z != NULL) {
        if (data < z->data)
            z = z->left;
        else if (data > z->data)
            z = z->right;
        else {
            deleteNode(root, z);
            return;
        }
    }
    printf("Node with data %d not found in the tree.\n", data);
}

// Function to print Red-Black-tree look like tree.
void printTree(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    
    printf("(%d, %s)\n", root->data, (root->color == BLACK) ? "B" : "R");

    printTree(root->left, space);
}

// Function to free memory of the tree
void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

// Main function
int main() {
    struct Node *root = NULL;

    // Example: Inserting nodes into Red-Black Tree
    insert(&root, 40);
    insert(&root, 38);
    insert(&root, 31);
    insert(&root, 12);
    insert(&root, 19);
    insert(&root, 8);
    insert(&root, 41);

    printf("Original Red-Black Tree:\n");
    printTree(root, 0);

    // Example: Deleting nodes from Red-Black Tree
    delete(&root, 12);
    delete(&root, 38);
    delete(&root,8);
    printf("\nRed-Black Tree after deletions:\n");
    printTree(root, 0);

    // Free memory for the remaining nodes
    freeTree(root);

    return 0;
}
