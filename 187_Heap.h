//
// Created by Zeno on 2019/9/27.
//

#ifndef UNTITLED1_187_HEAP_H
#define UNTITLED1_187_HEAP_H

#endif //UNTITLED1_187_HEAP_H

//左子节点 = 2*父节点 +1
//右子节点 = 2*父节点+2
//父节点 = （子节点-1）/2
//堆中最后一个非叶子节点：（n-2）/2
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int HPDataType;
typedef struct Heap{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

void swap(HPDataType* a,HPDataType* b);
void HeapInit(Heap* hp,HPDataType* a,int n);
void HeapInit2(Heap* hp);

void ShiftDown(HPDataType* a,int length,int root);
void ShiftUp(HPDataType* a,int lengeh,int child);

void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp,HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

//堆排序
void HeapSort(int *a,int n);

void Test();
