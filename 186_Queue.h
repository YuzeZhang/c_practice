//
// Created by Zeno on 2019/9/25.
//

#ifndef UNTITLED1_185_QUEUE_H
#define UNTITLED1_185_QUEUE_H

#endif //UNTITLED1_185_QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef int ElemType;
typedef struct QueueNode{
    struct QueueNode* _next;
    ElemType _data;
}QueueNode;

typedef struct Queue{
    QueueNode* _front;
    QueueNode* _rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueueIn(Queue* pq,ElemType x);
void QueueOut(Queue* pq);
ElemType QueueFront(Queue* pq);
ElemType QueueRear(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

struct Queue q;
