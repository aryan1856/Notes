/*
    Why Linked Lists?
   
    Linked list are the non contigous linear data structure - 
    Unlike array, where data needs to be stored in contigous memory , nodes of a linked list are not stored in contigous memory. Each node is connected via pointers.

    Memory efficiency-
    Since Linked Lists don't require the contigous memory allocation(as in arrays), the memory can be utilised efficiently. In case we need to store 100 elements but don't have contigous memmory, we can store them at different memory locations and access them using pointers

    Advantages-
    ease in insertion and deletion

    Drawbacks-
    Accessing data takes linear time i.e. O(n)
    Need extra space to store a pointer reference for each next node

*/

//INSERTION OPERATIONS IN LINKED LISTS

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

void insert_begin(){
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&node->data);
    node->next = head;
    head = node;
}

struct Node* insert_before_index(struct Node* temp, int idx){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = temp;
    int i=0;
    while(i!=idx-2){
        p = p->next;
        i++;
    }
    
    printf("Enter node data : ");
    scanf("%d",&ptr->data);
    
    ptr->next = p->next;
    p->next = ptr;
    
    return temp;
}

struct Node* insert_after_index(struct Node* temp, int idx){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = temp;
    int i=0;
    while(i!=idx){
        p = p->next;
        ++i;
    }
    printf("Enter node data : ");
    scanf("%d",&ptr->data);
    
    ptr->next = p->next;
    p->next = ptr;
    
    return temp;
}

void insert_end(){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->next != NULL)
        p = p->next;
    
    scanf("%d",&node->data);
    node->next = NULL;
    p->next = node;
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

void insert_after_node(struct Node* prev){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p != prev)
        p = p->next;
        
    scanf("%d",&node->data);
    node->next = p->next;
    p->next = node;
}


void main(){
    int i=5;
    while(i--)
        create();
    display();
    insert_begin();
    head = insert_before_index(head,2);
    head = insert_after_index(head,3);
    insert_end();
    struct Node* prev = head;
    insert_after_node(prev);
    display();
}