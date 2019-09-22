//
// Created by Zeno on 2019/9/29.
//

#ifndef UNTITLED1_188_BINARYTREE_H
#define UNTITLED1_188_BINARYTREE_H

#endif //UNTITLED1_188_BINARYTREE_H

#include <stdio.h>
#include <malloc.h>

//二叉树的链式存储方式 --- 孩子表示法
typedef int BTDataType;
typedef struct BTNode{
    BTDataType _data;
    struct BTNode* _left;
    struct BTNode* _right;
}BTNode;

void PreOrder(BTNode* pRoot);
BTNode* BTCreate(BTDataType* a,int* pi);
void BTDestroy(BTNode* pRoot);
