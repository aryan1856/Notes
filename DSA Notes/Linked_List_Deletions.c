#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// O(1)
void create() {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    scanf("%d", &node->data);
    node->next = NULL;
    if (head == NULL)
        head = node;
    else {
        struct Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

// O(1)
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* p = head;
    head = head->next;
    free(p);
}

// O(n)
void delete_between(int idx) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (idx <= 0) {
        printf("Invalid index\n");
        return;
    }
    struct Node* p = head;
    if (idx == 1) {
        head = head->next;
        free(p);
        return;
    }
    int i = 1;
    while (i < idx - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) {
        printf("Index out of bounds\n");
        return;
    }
    struct Node* q = p->next;
    p->next = q->next;
    free(q);
}

//O(n)
void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* p = head;
    if (p->next == NULL) {
        free(p);
        head = NULL;
        return;
    }
    struct Node* q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}

//O(n)
void delete_with_key(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* p = head;
    struct Node* q = NULL;
    while (p != NULL && p->data != key) {
        q = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Key not found\n");
        return;
    }
    if (q == NULL) { // If the key is in the first node
        head = head->next;
    } else {
        q->next = p->next;
    }
    free(p);
}

// O(n)
void display() {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int i = 5;
    while (i--)
        create();
    printf("Original list: ");
    display();
    delete_begin();
    delete_between(2);
    delete_last();
    delete_with_key(3);
    printf("List after deletion: ");
    display();

    // Freeing allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
