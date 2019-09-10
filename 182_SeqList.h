//
// Created by zeno on 2019/9/10.
//

#ifndef UNTITLED1_182_SEQLIST_H
#define UNTITLED1_182_SEQLIST_H

#endif //UNTITLED1_182_SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT_SIZE 10

typedef int SLDataType;

void SeqListInit(SeqList* psl,size_t capacity); //初始化接口
void SeqListDestory(SeqList* psl); //销毁接口

void CheckCapacity(SeqList* psl); //检查容量接口
void PushBack(SeqList* psl,SLDataType x); //尾插
void PopBack(SeqList* psl); //尾删
void PushFront(SeqList* psl,SLDataType x); //头插
void PopFront(SeqList* psl); //头删

int SeqListFind(SeqList* psl,SLDataType x); //查找接口
void SeqListInsert(Seqlist* psl,size_t pos,SLDataType x); //中间插
void SeqListErase(SeqList* psl,size_t pos); //中间删
void SeqListRemove(SeqList* psl,SLDataType x); //删除指定元素
void SeqListModify(SeqList* psl,size_t pos,SLDataType x); //修改元素
void SeqListPrint(SeqList* psl); //打印接口

void SeqListBubbleSort(SeqList* psl); //冒泡排序接口

void SeqListRemoveAll(SeqList* psl,SLDataType x); //删除所有指定元素
