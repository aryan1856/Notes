#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postOrder(Node* root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}

void main(){
    Node *root = createNode(5);
    root->left = createNode(10);
    root->right = createNode(100);
    root->left->left = createNode(15);
    root->left->left->left = createNode(20);
    root->left->left->right = createNode(25);
    root->left->right = createNode(30);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postOrder(root);
}