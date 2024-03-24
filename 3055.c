#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    int count;
    Node *rear; //가장 최근(뒤) 노드의 주소
    Node *front; // 가장 과거(앞)의 노드 주소
}Queue;

void initQueue(Queue *queue){
    return queue -> count =0;
}

int isempty(Queue *queue){
    return queue->count == 0;
}

void enqueue(Queue *queue, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(isempty(queue)){
        queue->front = newNode;
    }else{
        queue->rear->next = newNode;
    }
    queue -> rear = newNode;
    queue -> count++;
}

int dequeue(Queue *queue){
    int data;
    Node *ptr;
    if(isempty(queue)){
        printf("Error, Queue is empty!\n");
        return 0;
    }
    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;

    return data;
}