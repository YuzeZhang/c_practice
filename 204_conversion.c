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
    STDataType* _base; //ջ��
    STDataType* _top; //ջ��
    int _capacity; //����
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
    //�ж�ջ�Ƿ�����
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
    printf("ջΪ�գ�");
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
        if(x>9){ //ʮ������ʱ�����ĸ
            x=x+55;
            printf("%c",x);
        }else
            printf("%d",x);
    }
    printf("\n");
}
int main(){
    int n,N;
    printf("������Ҫת��������Ҫת���ɵĽ���(�м��ÿո����):");
    scanf("%d %d",&n,&N);
    StackInit(&st);
    printf("%dת��Ϊ%d���ƺ�Ϊ��",n,N);
    convert(&st,n,N);
    StackDestroy(&st);
    return 0;
}
