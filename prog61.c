//Delete Node from the BST
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
//create new node
struct Node * createNode(int value){
    struct Node * node;
    node=(struct Node *)malloc(sizeof(struct Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}
// printing inorder traversal
void printinOrder(struct Node *root) {
if (root != NULL) {
printinOrder(root->left);
printf("%d ", root->data);
printinOrder(root->right);
}
}
//find inordersuccessor of right subtree
struct Node * inordersucc(struct Node * root){
    struct Node * curr=root;
    while(curr && curr->left != NULL){
        curr=curr->left;
    }
    return curr;
}
//delete element
struct Node * deleteNode(struct Node * root, int key){
    if(root==NULL){
        return root;
    }
    //finding position of the node
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(root->data<key){
        root->right=deleteNode(root->right,key);
    }
    else {
        // if the element are leaf node
        if(root->left == NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        // if the element are containg right child only
        else if(root->left==NULL){
            struct Node * temp=root->right;
            free(root);
            return temp;
        }
        // if the element are containing left child only
        else if(root->right==NULL){
            struct Node * temp=root->left;
            free(root);
            return temp;
        }
        // if the child are containg both child
        else{
            struct Node * temp=inordersucc(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    struct Node * root=createNode(8);
    struct Node * c1=createNode(3);
    struct Node * c2=createNode(10);
    struct Node * c3=createNode(1);
    struct Node * c4=createNode(6);
    struct Node * c5=createNode(14);
    struct Node * c6=createNode(4);
    struct Node * c7=createNode(7);
    /*
                 8
               /   \
              3     10
            /   \      \   
           1     6      14
                /  \
               4    7

    */
   //linking elements
   root->left=c1;
   root->right=c2;
   c1->left=c3;
   c1->right=c4;
   c2->right=c5;
   c4->left=c6;
   c4->right=c7; 
   printinOrder(root);
   printf("\n");
//    struct Node * n=inordersucc(c1->right);
//    printf("%d",n->data);
int num;
printf("Enter the the element want to delete:");
scanf("%d",&num);
struct Node * n=deleteNode(root,num);
printf("root is: %d",n->data);
printf("\n");
printinOrder(root);
   return 0;          
}
