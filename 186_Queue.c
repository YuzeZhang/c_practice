//
// Created by Zeno on 2019/9/25.
//

#include "186_Queue.h"
void QueueInit(Queue* pq){
    pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
    assert(pq->_front);
    pq->_rear = pq->_front;
    pq->_front->_next = NULL;
}
void QueueDestroy(Queue* pq){
    while (pq->_front){
        pq->_rear = pq->_front->_next;
        free(pq->_front);
        pq->_front = pq->_rear;
    }
}
void QueueIn(Queue* pq,ElemType x){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    assert(newNode);
    newNode->_data = x;
    newNode->_next = NULL;
    pq->_rear->_next = newNode;
    pq->_rear = newNode;
}
void QueueOut(Queue* pq){
    if(pq->_front == pq->_rear)
        return;
    if(pq->_front->_next == pq->_rear){
        pq->_rear = pq->_front;
    }
    QueueNode* adjust = pq->_front->_next;
    pq->_front->_next = adjust->_next;
    free(adjust);
}
ElemType QueueFront(Queue* pq){
    if(pq->_front == pq->_rear){
        return 0;
    }
    return (pq->_front->_next)->_data;
}
ElemType QueueRear(Queue* pq){
    if(pq->_front == pq->_rear){
        return 0;
    }
    return (pq->_rear)->_data;
}
int QueueEmpty(Queue* pq){
    if(pq->_front == pq->_rear)
        return 1;
    return 0;
}
int QueueSize(Queue* pq){
    if(pq->_front == pq->_rear)
        return 0;
    int count = 0;
    QueueNode* p = pq->_front->_next;
    while(p){
        ++count;
        p = p->_next;
    }
    return count;
}
void test(){
    QueueInit(&q);
    QueueIn(&q,1);
    QueueIn(&q,2);
    QueueIn(&q,3);
    printf("%d\n",QueueSize(&q));
    QueueOut(&q);
    printf("%d\n",QueueSize(&q));
    QueueDestroy(&q);
}
int main(){
    test();
    return 0;
}
