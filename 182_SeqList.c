//
// Created by zeno on 2019/9/10.
//

#include "182_SeqList.h"



SeqList sl;

void SeqListInit(SeqList* sl,size_t capacity){
    sl->array = (SLDataType*)malloc(LIST_INCREMENT_SIZE* sizeof(SLDataType));
    if(sl->array == NULL){
        printf("��ʼ��ʧ�ܣ�\n");
        exit(0);
    }
    sl->size = 0;
    sl->capicity = LIST_INIT_SIZE;
}
void SeqListDestory(SeqList* sl){
    assert(sl);
    free(sl->array);
    sl->size = 0;
    printf("���ٳɹ���\n");
}
void PushFront(SeqList* sl,SLDataType x){
    assert(sl);
    CheckCapacity(sl);
    if(sl->size == 0){
        sl->array[0] = x;
    }else{
        for (size_t i = sl->size; i > 0 ; --i) {
            sl->array[i] = sl->array[i-1];
        }
        sl->array[0] = x;
    }
    ++sl->size;
    printf("��ӳɹ���\n");
}
void PushBack(SeqList* sl,SLDataType x){
    assert(sl);
    CheckCapacity(sl);
    sl->array[sl->size] = x;
    ++sl->size;
    printf("��ӳɹ���\n");
}
void CheckCapacity(SeqList* sl){
    assert(sl);
    if(sl->size == sl->capicity){
        sl->array = (SLDataType*)realloc(sl->array, sizeof(SLDataType)*LIST_INCREMENT_SIZE);
        sl->capicity+=LIST_INCREMENT_SIZE;
    }
}
void SeqListPrint(SeqList* sl){
    assert(sl);
    if(sl->size==0){
        printf("˳�������Ԫ�أ�\n");
        return;
    }
    for (int i = 0; i <= sl->size - 1; ++i) {
        if(i == sl->size-1){
            printf("%d\n",sl->array[i]);
            return;
        }
        printf("%d,",sl->array[i]);
    }
}
void PopBack(SeqList* sl){
    assert(sl);
    if(sl->size==0){
        printf("˳�������Ԫ�أ�\n");
        return;
    }
    --sl->size;
    printf("ɾ���ɹ���\n");
}
void PopFront(SeqList* sl){
    assert(sl);
    if(sl->size==0){
        printf("˳�������Ԫ�أ�\n");
        return;
    }
    for (int i = 0; i < sl->size-1; ++i) {
        sl->array[i] = sl->array[i+1];
    }
    --sl->size;
    printf("ɾ���ɹ���\n");
}
void SeqListFind(SeqList* sl,SLDataType x){
    assert(sl);
    if(sl->size==0){
        printf("˳�������Ԫ�أ�\n");
        return;
    }
    int flag = 0;
    int i;
    for ( i = 0; i < sl->size; ++i) {
        if(x == sl->array[i]){
            flag = 1;
            printf("%d λ��˳���ĵ�%dλ��\n",x,i);
        }
    }
    if(flag == 0){
        printf("δ��˳������ҵ�%d\n",x);
    }
}
void SeqListInsert(SeqList* sl,size_t pos,SLDataType x){
    assert(sl);
    CheckCapacity(&sl);
    if(pos<0||pos>sl->size){
        printf("�����˴����λ�ã�\n");
        return;
    }
    if(pos == 0){
        PushFront(&sl,x);
        return;
    }
    if(pos == sl->size){
        PushBack(&sl,x);
        return;
    }
    for (int i = sl->size; i > pos; --i) {
        sl->array[i] = sl->array[i-1];
    }
    sl->array[pos] = x;
    printf("��ӳɹ���\n");
    ++sl->size;
}
int main(){
    SeqListInit(&sl,LIST_INIT_SIZE);
    PushFront(&sl,1);
    PushBack(&sl,2);
    PushBack(&sl,3);
    PushBack(&sl,2);
    SeqListPrint(&sl);
    SeqListFind(&sl,9);
    SeqListInsert(&sl,2,99);
    SeqListPrint(&sl);
    SeqListInsert(&sl,2,98);
    SeqListPrint(&sl);
    SeqListDestory(&sl);
    return 0;
}
