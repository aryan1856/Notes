#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct Stack{
    int top;
    int array[SIZE];
}Stack;

Stack* createStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack){
    return (stack->top == SIZE-1);
}

int isEmpty(Stack* stack){
    return (stack->top == -1);
}

void push(Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack is full");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow");
        return -1;
    }
    return stack->array[stack->top--];
}

typedef struct Queue{
    Stack *input;
    Stack *output;
}Queue;

void enqueue(Queue *queue, int data){
    push(queue->input,data);
}

int dequeue(Queue* queue){
    if(isEmpty(queue->input) && isEmpty(queue->output)){
        printf("Empty queue");
        return -1;
    }
    if(isEmpty(queue->output)){
        while(!isEmpty(queue->input))
            push(queue->output, pop(queue->input));
    }
    return pop(queue->output);
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->input = createStack();
    queue->output = createStack();

    int i;
    for(i=1;i<=10;i++)
        enqueue(queue, i*5);
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    enqueue(queue, 4);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}