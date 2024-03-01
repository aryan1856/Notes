//STACK IMPLEMENTATION WITH STRUCT
#include<stdio.h>

#define MAX_SIZE 1000

typedef struct{
    int top;
    int items[MAX_SIZE];
}Stack;

void initialize(Stack* stack, int top){
    stack->top = -1;
}

int isEmpty(Stack* stack){
    return (stack->top == -1);
}

int isFull(Stack* stack){
    return (stack->top == MAX_SIZE-1);
}

void push(Stack* stack, int data){
    if(isFull(stack)){
        printf("\nOverflow");
        return;
    }
    stack->items[++stack->top] = data;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("\nUnderflow");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    return stack->items[stack->top];
}

void show(Stack *stack) {
    if (!isEmpty(stack)) {
        int element = pop(stack);
        printf("%d ", element);
        show(stack);
        push(stack, element);
    }
}

void main(){
    Stack stack;
    initialize(&stack,-1);
    int i=1;
    for(i=1;i<=1000;i++){
        push(&stack,i);
    }
    printf("%d",peek(&stack));
}


//STACK IMPLEMENTATION WITHOUT STRUCT

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global variables for stack and top index
int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Function to get the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Elements: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
