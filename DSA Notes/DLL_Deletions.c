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

void deleteNode(int pos){
    if(head==NULL)
        return;
    else if(pos==1){
        Node* temp = head;
        head=head->next;
        head->prev = NULL;
        free(temp);
    }
    else{
        int i=1;
        Node* p = head;
        while(i<pos-1){
            p = p->next;
            i++;
        }
        Node* temp = p->next;
        p->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = p;
        else
            tail = p; // Update tail if the last node is deleted
        free(temp);
    }
}

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
    insert(100);
    insert(1927);
    display(head,0);
    deleteNode(1);
    deleteNode(3);
    deleteNode(3);
    display(head,0);
    
    return 0;
}
