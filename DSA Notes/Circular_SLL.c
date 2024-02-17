#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* tail = NULL;

void insert(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        tail->next = tail; // Circular linked list
    } else {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
}

void insertAtPos(int pos, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if (pos == 1) {
        if (tail == NULL) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
        }
    } else {
        struct Node* p = tail->next;
        int i = 1;
        while (i < pos - 2 && p->next != tail) { // Stop if we reach tail's predecessor
            p = p->next;
            ++i;
        }
        if (p->next == tail && i < pos - 2) {
            printf("Error: Position %d exceeds the length of the list\n", pos);
            free(node);
            return;
        }
        node->next = p->next;
        p->next = node;
        if (p == tail) {
            tail = node; // Update tail if the new node is inserted at the end
        }
    }
}


void print(struct Node *temp) {
    struct Node* current = temp;
    if (temp != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != temp);
    }
    printf("\n");
}

int main() {
    insert(5);
    insert(10);
    insert(11);
    insert(53);
    insert(9);
    print(tail);
    insertAtPos(5,2);
    print(tail);
    return 0;
}
