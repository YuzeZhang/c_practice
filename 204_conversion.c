//
// Created by Zeno on 2019/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_INIT_SIZE 100
#define INCREMENT 10
typedef int STDataType;
typedef struct Stack{
    STDataType* _base; //栈底
    STDataType* _top; //栈顶
    int _capacity; //容量
}Stack;
Stack st;
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
int StackSize(Stack* ps){
    return ps->_top - ps->_base;
}
int StackEmpty(Stack* ps){
    if(StackSize(ps) == 0)
        return 1;
    return 0;
}
STDataType StackTop(Stack* ps){
    return *(ps->_top - 1);
}
void convert(Stack *ps,int N,int n){
    int i,x;
    do{
    StackPush(ps,N%n);
    N/=n;
    } while (N!=0);

    while(!StackEmpty(ps)){
        x=StackPop(ps);
        if(x>9){ //十六进制时输出字母
            x=x+55;
            printf("%c",x);
        }else
            printf("%d",x);
    }
    printf("\n");
}
int main(){
    int n,N;
    printf("请输入要转换的数和要转换成的进制(中间用空格隔开):");
    scanf("%d %d",&n,&N);
    StackInit(&st);
    printf("%d转换为%d进制后为：",n,N);
    convert(&st,n,N);
    StackDestroy(&st);
    return 0;
}
