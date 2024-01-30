// The queue is a data structure that follows FIFO(First-in first-out) paradigm
// Queues have basic operations like stack i.e. enqueue(push), dequeue(pop), isFull(), isEmpty() etc
// the enqueue operation takes place at the rear end
// the dequeue operation takes place at the front end
// initially we take both front and rear as -1(non-valid index)
// Queues can be implemented using Arrays, Stacks and LinkedLists

// TYPES OF QUEUES
// 1 - Linear queue
// 2 - circular queue
// 3 - deque 
// 4 - Priority queue

//ARRAY IMPLEMENTATION OF A LINEAR(BASIC) QUEUE

#include<stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *arr;
};

int isFull(struct Queue *Q);
int isEmpty(struct Queue *q);

void enqueue(struct Queue *q, int data){
    if(isFull(q))
        printf("Queue Overflow!\n");
    else{
        q->rear = q->rear+1;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q))
        printf("Nothing to remove, underflow\n");
    else{
        q->front++;
        a= q->arr[q->front];
    }
    return a;
}

int isFull(struct Queue *Q){
    if(Q->size-1 == Q->rear)
        return 1;
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->rear == q->front)
        return 1;
    return 0;
}

void show(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

void main(){
    struct Queue q;
    q.size = 10;
    q.front = -1;
    q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    
    show(&q);
    enqueue(&q,10);
    enqueue(&q,45);
    enqueue(&q,87);
    show(&q);
    dequeue(&q);
    enqueue(&q,7);
    show(&q);
    
    free(q.arr);
}