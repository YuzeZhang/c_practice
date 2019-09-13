//
// Created by Zeno on 2019/9/21.
//

#ifndef UNTITLED1_184_STACK_H
#define UNTITLED1_184_STACK_H

#endif //UNTITLED1_184_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_INIT_SIZE 1
#define INCREMENT 1
typedef int STDataType;
typedef struct Stack{
    STDataType* _base; //栈底
    STDataType* _top; //栈顶
    int _capacity; //容量
}Stack;
Stack st;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps,STDataType x); //压栈
STDataType StackPop(Stack* ps); //出栈
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void test();
