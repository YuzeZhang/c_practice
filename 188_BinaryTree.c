//
// Created by Zeno on 2019/9/29.
//
#include "188_BinaryTree.h"


void PreOrder(BTNode* pRoot){
    if(pRoot){
        printf("%d ",pRoot->_data);
        PreOrder(pRoot->_left);
        PreOrder(pRoot->_right);
    }
}
void InOrder(BTNode* pRoot){
    if(pRoot){
        InOrder(pRoot->_left);
        printf("%d ",pRoot->_data);
        InOrder(pRoot->_right);
    }
}
void PostOrder(BTNode* pRoot){
    if(pRoot){
        PostOrder(pRoot->_left);
        PostOrder(pRoot->_right);
        printf("%d ",pRoot->_data);
    }
}
BTNode* BTCreate(BTDataType* a,int* pi){

}
void BTDestroy(BTNode* pRoot){
    if(pRoot){
        PostOrder(pRoot->_left);
        PostOrder(pRoot->_right);
        free(pRoot);
    }
}
