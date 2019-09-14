//
// Created by Zeno on 2019/9/21.
//
#include "184_Stack.h"
void StackInit(Stack* ps){
    ps->_base = (STDataType*)malloc(sizeof(STDataType)*STACK_INIT_SIZE);
    assert(ps->_base);
    ps->_top = ps->_base;
    ps->_capacity = STACK_INIT_SIZE;
}
void StackDestroy(Stack* ps){
    free(ps->_base);
    ps->_base = NULL;
    ps->_top = NULL;
    ps->_capacity = 0;
}

void StackPush(Stack* ps,STDataType x){
    //判断栈是否已满
    if(ps->_top - ps->_base>=ps->_capacity){
        Stack temp;
        temp._base = (STDataType*)realloc(ps->_base,sizeof(STDataType)*(INCREMENT+st._capacity));
        assert(temp._base);
        ps->_base = temp._base;
        ps->_top = ps->_base + ps->_capacity;
        ps->_capacity+=INCREMENT;
    }
    *(ps->_top++) = x;
}
STDataType StackPop(Stack* ps){
    if(ps->_top!=ps->_base){
        ps->_top--;
        return *(ps->_top);
    }
    printf("栈为空！");
    return 0;
}
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps){
    if(StackSize(ps) == 0)
        return 1;
    return 0;
}
int StackSize(Stack* ps){
    return ps->_top - ps->_base;
}
STDataType StackTop(Stack* ps){
    return *(ps->_top - 1);
}
void test(){
    StackInit(&st);
    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    StackPush(&st,4);
    printf("%d\n",StackPop(&st));
    printf("%d\n",StackTop(&st));
    printf("%d\n",StackPop(&st));
    printf("%d\n",StackTop(&st));
    printf("%d\n",StackPop(&st));
    printf("%d\n",StackPop(&st));
    StackDestroy(&st);
}
int main(){
    test();
    return 0;
}
