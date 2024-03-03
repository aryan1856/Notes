#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Stack{
    Node* top;
}Stack;

Stack* createStack(){
    Stack * stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack){
    return (!stack->top);
}

void push(Stack* stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow");
        return -1;
    }
    Node* node = stack->top;
    int e = node->data;
    stack->top = stack->top->next;
    node->next = NULL;
    free(node);
    return e;
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Empty stack");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));

    printf("Top element is %d\n", peek(stack));

    return 0;
}
