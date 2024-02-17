#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insert(int data){ //inserting at the end
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if(head == NULL){
        head = node;
        tail = head;
    }
    else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void insertAtPos(int pos, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next=NULL;
    node->prev=NULL;
    if(pos==1){
        node->next = head;
        head->prev = node;
        head = node;
    }
    else if(head==NULL){
        head = node;
        tail = node;
    }
    else{
        Node* p = head;
        int i = 1;
        while(i<pos-1){
            p = p->next;
            i++;
        }
        Node* temp = p->next;
        p->next = node;
        node->prev = p;
        node->next = temp;
        
        if(temp != NULL)
            temp->prev = node;
        if(p == tail)
            tail = node;
    }
}

// void display(Node* p){
//     if(p != NULL){
//         printf("%d ", p->data);
//         display(p->next);
//     }
// }

// void displayReverse(Node* p){
//     if(p != NULL){
//         printf("%d ", p->data);
//         displayReverse(p->prev);
//     }
// }
void display(Node* p, int reverse){
    if(reverse){
        while(p != NULL){
            printf("%d ", p->data);
            p = p->prev;
        }
    } else {
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
    }
    printf("\n");
}


int main(){    
    insert(5);
    insert(10);
    insert(11);
    
    printf("Forward traversal: ");
    display(head,0);
    
    printf("Reverse traversal: ");
    display(tail,1);
    
    insertAtPos(2,9);
    insertAtPos(5,90);
    display(head,0);
    display(tail,1);
    
    return 0;
}