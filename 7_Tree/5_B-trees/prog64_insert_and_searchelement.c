#include <stdio.h>
#include <stdlib.h>

#define T 2

// B-tree node structure
typedef struct BTreeNode {
    int leaf; // 1 if node is a leaf, 0 if it's an internal node
    int n;    // Number of keys in the node
    int keys[2 * T - 1]; // Array to store keys
    struct BTreeNode* children[2 * T]; // Array to store child pointers
} BTreeNode;

// B-tree structure
typedef struct BTree {
    BTreeNode* root;
} BTree;

// Function to create a new B-tree node
BTreeNode* createNode() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->leaf = 1;
    newNode->n = 0;
    return newNode;
}

// Function to create a new B-tree
BTree* createBTree() {
    BTree* newBTree = (BTree*)malloc(sizeof(BTree));
    newBTree->root = createNode();
    return newBTree;
}

// Function to search for a key in the B-tree
int search(BTreeNode* x, int key) {
    int i = 0;
    while (i < x->n && key > x->keys[i]) {
        i++;
    }

    if (i < x->n && key == x->keys[i]) {
        return 1; // Key found
    } else if (x->leaf) {
        return 0; // Key not found
    } else {
        return search(x->children[i], key); // Recur to the appropriate child
    }
}

// Function to split a full child of a B-tree node
void splitChild(BTreeNode* x, int i) {
    BTreeNode* y = x->children[i];
    BTreeNode* z = createNode();
    z->leaf = y->leaf;
    z->n = T - 1;

    // Copy the last T-1 keys of y to z
    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = y->keys[j + T];
    }

    // If y is not a leaf, copy the last T children of y to z
    if (!y->leaf) {
        for (int j = 0; j < T; j++) {
            z->children[j] = y->children[j + T];
        }
    }

    y->n = T - 1;

    // Shift keys and children in x to make space for the new child
    for (int j = x->n; j > i; j--) {
        x->keys[j] = x->keys[j - 1];
        x->children[j + 1] = x->children[j];
    }

    x->keys[i] = y->keys[T - 1];
    x->children[i + 1] = z;
    x->n++;
}

// Function to insert a key into a B-tree
void insert(BTree* tree, int key) {
    BTreeNode* root = tree->root;

    if (root->n == 2 * T - 1) {
        // If the root is full, create a new root
        BTreeNode* newRoot = createNode();
        tree->root = newRoot;
        newRoot->leaf = 0;
        newRoot->n = 0;
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
    } else {
        insertNonFull(root, key);
    }
}

// Function to insert a key into a non-full B-tree node
void insertNonFull(BTreeNode* x, int key) {
    int i = x->n - 1;

    if (x->leaf) {
        // If x is a leaf, insert the key into it
        while (i >= 0 && key < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = key;
        x->n++;
    } else {
        // If x is not a leaf, find the child to insert into
        while (i >= 0 && key < x->keys[i]) {
            i--;
        }

        i++;

        // If the child is full, split it
        if (x->children[i]->n == 2 * T - 1) {
            splitChild(x, i);

            // Determine which of the two children to descend to
            if (key > x->keys[i]) {
                i++;
            }
        }

        // Recur to the appropriate child
        insertNonFull(x->children[i], key);
    }
}

// Function to print the B-tree in-order
void inOrderTraversal(BTreeNode* x) {
    if (x) {
        int i;
        for (i = 0; i < x->n; i++) {
            if (!x->leaf) {
                inOrderTraversal(x->children[i]);
            }
            printf("%d ", x->keys[i]);
        }

        if (!x->leaf) {
            inOrderTraversal(x->children[i]);
        }
    }
}

int main() {
    BTree* btree = createBTree();

    // Insert elements into the B-tree
    int elements_to_insert[] = {3, 7, 1, 8, 5, 12, 10, 6, 9};
    int num_elements = sizeof(elements_to_insert) / sizeof(elements_to_insert[0]);

    for (int i = 0; i < num_elements; i++) {
        insert(btree, elements_to_insert[i]);
    }

    // Search for elements in the B-tree
    int elements_to_search[] = {3, 7, 1, 8, 5, 12, 10, 6, 9, 11};
    int num_elements_to_search = sizeof(elements_to_search) / sizeof(elements_to_search[0]);

    for (int i = 0; i < num_elements_to_search; i++) {
        if (search(btree->root, elements_to_search[i])) {
            printf("%d is present in the B-tree.\n", elements_to_search[i]);
        } else {
            printf("%d is not present in the B-tree.\n", elements_to_search[i]);
        }
    }

    // Print the B-tree in-order
    printf("B-tree in-order traversal: ");
    inOrderTraversal(btree->root);
    printf("\n");

    return 0;
}
