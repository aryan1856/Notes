/* There are some drawbacks in the linear queue and one of the most important is
We can't use the space efficiently that means even if we have a box empty in the queue still we can't add a new 
element
Therefore, the concept f circular queue comes in use, we will use circular increment to the front and rear
instead of using linear increment so that we can use the empty spaces efficiently */

// CIRCULAR QUEUE IMPLEMENTATION-

#include<stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *arr;
};

void enqueue(struct Queue *q, int data){
    if((q->rear+1)%q->size == q->front)
        printf("Queue Overflow");
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    int e = -1;
    if(q->rear == q->front)
        printf("Underflow");
    else{
        q->front = (q->front+1)%q->size;
        e = q->arr[q->front];
    }
    return e;
}

void show(struct Queue *q){
    if(q->rear == q->front){
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
    q.size = 5;
    q.front = -1;
    q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    int i;
    show(&q);
    for(i=0;i<2*q.size;i++){
        enqueue(&q,i+1);
    }
    show(&q);
    
    free(q.arr);
}

// this program will output as 6,7,8,9,10