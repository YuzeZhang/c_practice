//
// Created by zeno on 2019/9/15.
//

#ifndef UNTITLED1_183_SINGLELINKEDLIST_H
#define UNTITLED1_183_SINGLELINKEDLIST_H

#endif //UNTITLED1_183_SINGLELINKEDLIST_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int SLLDataType;
typedef struct SLListNode{
    SLLDataType _data;
    struct SLListNode* _next;
}SLListNode;

typedef struct SLList{
    SLListNode* _head;
}SLList;

void SLListInit(SLList* plist);
void SLListDestroy(SLList* plsit);

SLListNode* NodeCreat(SLLDataType x);
void SLListPushFront(SLList* plist,SLLDataType x);
void SLListPushBack(SLList* plist,SLLDataType x);
void SLListPopFront(SLList* plist);
void SLListPopBack(SLList* plist);
SLListNode* SLListFind(SLList* plist,SLLDataType x);

void SLListInsertAfter(SLListNode* pos,SLLDataType x);  //在pos的后面插入
void SLListEraseAfter(SLListNode* pos);
void SLListRemove(SLList* plist,SLLDataType x);

void SLListPrint(SLList* plist);

void test();
