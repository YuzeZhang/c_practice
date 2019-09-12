//
// Created by zeno on 2019/9/15.
//

#include "183_SingleLinkedList.h"

void SLListInit(SLList* plist){
    assert(plist);
    plist->_head = NULL;
    printf("单链表创建成功！\n");
}
SLListNode* NodeCreat(SLLDataType x){
    SLListNode* newNode = (SLListNode*)malloc(sizeof(SLListNode*));
    newNode->_data = x;
    newNode->_next = NULL;
    return newNode;
}
void SLListDestroy(SLList* plist){
    assert(plist);
    SLListNode* cur = plist->_head;
    SLListNode* next;
    while (cur){
        next = cur->_next;
        free(cur);
        cur = next;
    }
    plist->_head = NULL;
    printf("单链表已被销毁！\n");
}
void SLListPushFront(SLList* plist,SLLDataType x){
    assert(plist);
    SLListNode* newNode = NodeCreat(x);
    newNode->_next = plist->_head;
    plist->_head = newNode;
}
void SLListPrint(SLList* plist){
    assert(plist);
    SLListNode* cur = plist->_head;
    if(cur == NULL){
        printf("单链表内无元素!\n");
        return;
    }
    while (cur){
        printf("%d ",cur->_data);
        cur = cur->_next;
    }
    printf("\n");
}
void SLListPushBack(SLList* plist,SLLDataType x){
    assert(plist);
    SLListNode* newNode = NodeCreat(x);
    SLListNode* cur = plist->_head;
    if(cur == NULL){
        plist->_head = newNode;
        return;
    }
    SLListNode* next = cur->_next;
    while (next){
        cur = next;
        next = cur->_next;
    }
    cur->_next = newNode;
}
void SLListPopFront(SLList* plist){
    assert(plist);
    SLListNode* cur = plist->_head;
    if (cur == NULL){
        printf("单链表为空！\n");
        return;
    }
    SLListNode* next = cur->_next;
    free(cur);
    cur = NULL;
    plist->_head = next;
}
void SLListPopBack(SLList* plist){
    assert(plist);
    SLListNode* cur = plist->_head;
    //单链表为空时
    if (cur == NULL){
        printf("单链表为空！\n");
        return;
    }
    SLListNode* next = cur->_next;
    //单链表只有一个元素时
    if(next == NULL){
        free(plist->_head);
        plist->_head = NULL;
        return;
    }
    while (next->_next){
        cur = next;
        next = cur->_next;
    }
    cur->_next = NULL;
    free(next);
    next = NULL;
}
SLListNode* SLListFind(SLList* plist,SLLDataType x){
    assert(plist);
    SLListNode* cur = plist->_head;
    if(cur == NULL){
        printf("单链表为空！\n");
        return NULL;
    }
    SLListNode* next = cur->_next;
    while (next){
        if (cur->_data == x){
            return cur;
        }
        cur = next;
        next = cur->_next;
    }
    if(next == NULL){
        if (cur->_data == x){
            return cur;
        }
    }
    return NULL;
}
void SLListInsertAfter(SLListNode* pos,SLLDataType x){
    if(pos == NULL){
        printf("操作的节点位置不存在！\n");
        return;
    }
    SLListNode* next_original = pos->_next;
    SLListNode* newNode = NodeCreat(x);
    newNode->_next = next_original;
    pos->_next = newNode;
}
void SLListEraseAfter(SLListNode* pos){
    if(pos == NULL){
        printf("操作的节点位置不存在！\n");
        return;
    }
    SLListNode* next_original = pos->_next;
    if(next_original == NULL){
        printf("该节点已经是最后一个节点！\n");
        return;
    }
    SLListNode* next_new = next_original->_next;
    free(next_original);
    next_original = NULL;
    pos->_next = next_new;
}
void SLListRemove(SLList* plist,SLLDataType x){
    assert(plist);
    SLListNode* cur = plist->_head;
    SLListNode* prev = NULL;
    while (cur){
        if(cur->_data == x){
            if(prev == NULL){
                plist->_head = cur->_next;
                free(cur);
                cur = plist->_head;
            }else{
                prev->_next = cur->_next;
            }
            free(cur);
            cur = prev;
        } else{
            prev = cur;
            cur = cur->_next;
        }
    }
}
void test(){
    SLList sll;
    SLListInit(&sll);
    SLListPushFront(&sll,3);
    SLListPushFront(&sll,2);
    SLListPushFront(&sll,3);
    SLListPushFront(&sll,3);
    SLListPushFront(&sll,3);
    SLListPushFront(&sll,4);
    SLListPushBack(&sll,3);
    SLListInsertAfter(SLListFind(&sll,100),9);
    SLListPrint(&sll);
    SLListEraseAfter(SLListFind(&sll,100));
    SLListPrint(&sll);
    SLListRemove(&sll,3);
    SLListPrint(&sll);
    SLListDestroy(&sll);
}
int main(){
    test();
    return 0;
}
