//
// Created by Zeno on 2019/10/1.
//

#ifndef UNTITLED1_189_LINKLIST_H
#define UNTITLED1_189_LINKLIST_H

#endif //UNTITLED1_189_LINKLIST_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int LTDataType;
typedef struct ListNode{
    LTDataType _data;
    struct ListNode* _prev;
    struct ListNode* _next;
}ListNode;

typedef struct List{
    ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestroy(List* plist);

ListNode* CreatNode(LTDataType x);
void ListPushBack(List* plist,LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist,LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist,LTDataType x);

//在pos前面插入
void ListInsert(ListNode* pos,LTDataType x);

//删除pos位置的节点
void ListErase(ListNode* pos);

void ListRemove(List* plist,LTDataType x);

void ListPrint(List* plist);

void Test();
