//Insert operation in Red-Black-Tree 
#include <stdio.h>
#include <stdlib.h>

// Node structure for Red-Black Tree
struct Node {
    int data;
    struct Node *parent, *left, *right;
    int color;  // 0 for black, 1 for red
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->color = 1; // New nodes are always red
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

// Function to fix Red-Black Tree violations
void fixInsert(struct Node **root, struct Node *z) {
    while (z->parent != NULL && z->parent->color == 1) {
        //CASE:I (new node-> parent is left child and new node -> uncle is Right child )
        if (z->parent == z->parent->parent->left) {
            struct Node *y = z->parent->parent->right;
            if (y != NULL && y->color == 1)//newNode->uncle is (not null) and Red Perfrom RECOLOR
             {
                z->parent->color = 0;  // Flip colors
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;// Move up the tree to check for further violations
            }
             else//newNode->uncle is null or black perfrom rotation
               {
                if (z == z->parent->right) //RR Rotation
                {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 0;  // Flip colors
                z->parent->parent->color = 1;
                rightRotate(root, z->parent->parent); //LL Rotation
            }
        }
        //CASE: II (NewNode->parent is Right Child and NewNode->uncle is LeftChild)
         else
          {
            struct Node *y = z->parent->parent->left;
            if (y != NULL && y->color == 1) //newNode->uncle is (not null) and Red Perfrom RECOLOR
            {
                z->parent->color = 0;  // Flip colors
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;// Move up the tree to check for further violations
            }
             else // newNode->uncle is null or black perfrom rotation
             {
                if (z == z->parent->left) // LL Rotation 
                {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 0;  // Flip colors
                z->parent->parent->color = 1;
                leftRotate(root, z->parent->parent); // RR Rotation
            }
        }
    }

    (*root)->color = 0;  // Root always black
}

// Function to insert a node in Red-Black Tree
void insert(struct Node **root, int data) {
    // Regular BST insert
    struct Node *z = createNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;

    while (x != NULL)// Step 1: Traverse the tree to find the appropriate position for the new node
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    // Step 2: Update pointers to insert the new node into the tree
    z->parent = y;
    if (y == NULL) // If the tree is empty, set the new node as the root
        *root = z;
    else if (z->data < y->data)//Insert newNode  As a Left Child from parent
        y->left = z;                    
    else //Insert NewNode As a Right Child from parent
        y->right = z;

    // Fix Red-Black Tree violations
    fixInsert(root, z);
}

// Function to print Red-Black-tree look like tree.
void printTree(struct Node *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Print right subtree
    printTree(root->right, space);

    // Print current node
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    
     printf("(%d, %s)\n",root->data, (root->color == 0) ? "B" : "R");
    // Print left subtree
    printTree(root->left, space);
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
    insert(&root,41);
    printTree(root, 0);

    return 0;
}
