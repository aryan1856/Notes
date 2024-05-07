#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new BST node
Node* newNode(int item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with a given key in the BST
Node* insert(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Function to do inorder traversal of BST
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

//recursive search
Node* search(Node* root, int key){
    if(root==NULL)
        return NULL;
    if(root->key == key)
        return root;
    else if(root->key > key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

//interative search
Node* searchIterative(Node* root, int key){
    while(root!=NULL){
        if(root->key == key)
            return root;
        else if(root->key > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main() {
    Node *root = NULL;
    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 43);
    root = insert(root, 57);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 908);
    root = insert(root, 65);

    // Print in-order traversal of the BST
    printf("Inorder traversal of the given tree \n");
    inorder(root);
    
    Node* isPresent = searchIterative(root,90);
    if(!isPresent)  
        printf("Key Not Present");
    else
        printf("Key Present");

    return 0;
}
