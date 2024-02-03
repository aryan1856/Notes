#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(){
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&node->data);
    node->next=NULL;
    if(head==NULL)
        head = node;
    else{
        struct Node *ptr=head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

void insert_before(){
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&node->data);
    node->next = NULL;
    if(head==NULL)
        head = node;
    else{
        struct Node *temp = head;
        head = node;
        node->next = temp;
    }
}

void display(){
    if(head==NULL)
        return;
    else{
        struct Node *ptr=head;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void main(){
    int i=5;
    while(i--)
        create();
    display();
    insert_before();
    display();
}