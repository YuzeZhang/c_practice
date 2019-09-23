//
// Created by Zeno on 2019/10/1.
//

#include "189_LinkList.h"

void ListInit(List* plist){
    assert(plist);
    plist->_head = CreatNode(0);
    plist->_head->_prev = plist->_head;
    plist->_head->_next = plist->_head;
}

ListNode* CreatNode(LTDataType x){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->_data = x;
    newNode->_next = NULL;
    newNode->_prev = NULL;
    return newNode;
}
void ListPushBack(List* plist,LTDataType x){
    assert(plist);
    ListNode* newNode = CreatNode(x);
    ListNode* rear = plist->_head->_prev;
    newNode->_next = plist->_head;
    newNode->_prev = rear;
    rear->_next = newNode;
    plist->_head->_prev = newNode;
}
void ListPopBack(List* plist){
    assert(plist);
    if(plist->_head->_next == plist->_head) {
        printf("链表中无元素\n");
        return;
    }
    ListNode* rear = plist->_head->_prev;
    rear->_prev->_next = plist->_head;
    plist->_head->_prev = rear->_prev;
    free(rear);
}
void ListDestroy(List* plist){
    assert(plist);
    ListNode* cur = plist->_head->_next;
    while (cur != plist->_head){
        ListNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    free(plist->_head);
}

void ListPushFront(List* plist,LTDataType x){
    assert(plist);
    ListNode* newNode = CreatNode(x);
    ListNode* head = plist->_head->_next;
    plist->_head->_next = newNode;
    newNode->_prev = plist->_head;
    newNode->_next = head;
    head->_prev = newNode;
}
void ListPopFront(List* plist){
    assert(plist);
    ListNode* head = plist->_head->_next;
    plist->_head->_next = head->_next;
    head->_next->_prev = plist->_head;
    free(head);
}
void ListPrint(List* plist){
    assert(plist);
    ListNode* cur = plist->_head->_next;
    while (cur!=plist->_head){
        printf("%d ",cur->_data);
        cur = cur->_next;
    }
    printf("\n");
}
void Test(){
    List ls;
    ListInit(&ls);
    ListPushFront(&ls,4);
    ListPrint(&ls);
    ListPushFront(&ls,5);
    ListPrint(&ls);
    ListPushFront(&ls,6);
    ListPrint(&ls);
    ListPopFront(&ls);
    ListPrint(&ls);
    ListPopFront(&ls);
    ListPrint(&ls);
    ListPopFront(&ls);
    ListPrint(&ls);
    ListPopFront(&ls);
    ListPrint(&ls);
    ListDestroy(&ls);
}
int main(){
    Test();
    return 0;
}
