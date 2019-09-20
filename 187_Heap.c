//
// Created by Zeno on 2019/9/27.
//

#include "187_Heap.h"

void HeapInit(Heap* hp,HPDataType* a,int length){
    assert(hp && a);
    int i;
    hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * length);
    for (i = 0; i < length; ++i) {
        hp->_a[i] = a[i];
    }
    //从最后一颗子树开始调整
    for (i = (length-2)/length; i >= 0; --i) {
        ShiftDown(hp->_a,length,i);
    }
    hp->_size = length;
    hp->_capacity = length;
}
void swap(HPDataType* a,HPDataType* b){
    HPDataType temp = *a;
    *a = *b;
    *b = temp;
}
void ShiftDown(HPDataType* a,int length,int root){
    //注意：此调整算法应该从最后的子树开始调用，依次向上循环调用
    //向下调整，调整为大堆   O(logN)
    // (length-2)/2 ---> 最后一个非叶子节点的索引
    // 0 ~ (length-2)/2 ---> 所有非叶子节点的索引
    assert(a);
    int parent = root;
    int child = parent * 2 + 1;
    while(child < length){
        //循环条件是当当前节点有孩子时
        //是否有右孩子，如果有，取左右孩子中较大的
        if((child + 1 < length)&&a[child+1] > a[child])
            ++child;
        if(a[child] > a[parent]){
            swap(&a[child],&a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }else{
            //以parent为根的子树已经是一个大堆，结束调整
            break;
        }
    }
}
void ShiftUp(HPDataType* a,int lengeh,int child){
    assert(a);
    int parent = (child - 1)/2;
    while (child > 0){
        //判断孩子是否大于父亲
        if(a[child] > a[parent]){
            swap(a[child],a[parent]);
            child = parent;
            parent = (child - 1)/2;
        }else
            break;
    }
}
