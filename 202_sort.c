//
// Created by Zeno on 2019/10/13.
//

//插入排序
//for(i = 0;i<n-1;++i){
//    end = i;
//    tmp = a[end+1];
//    while(end >= 0 && a[end] > tmp){
//        a[end + 1] = a[end];
//        --end;
//    }
//    a[end + 1] = tmp;
//}

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void Swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void InsertSort(int* a,int n){
    assert(a);
    int i;
    for(i = 0;i<n-1;++i){
        //单个元素的排序
        //找到已经排好序的最后一个元素的位置
        int end = i;
        //把end+1位置的元素插入到合适的位置
        int tmp = a[end+1];
        while(end >= 0 && a[end] > tmp){
            a[end + 1] = a[end];
            --end;
        }
        //找到合适的位置
        a[end+1] = tmp;
    }
}
void ShellSort(int* a,int n){
    int gap = n;
    int i;
    //int num;
   // for(;gap >= 1;gap -= num){ //预排序的次数
   //     for(num = 0; num < gap; ++num){ //待排序的组别
   while(gap > 1) {
       //gap > 1 --->预排序
       //gap = 1 --->真正的排序
       gap = gap / 3 + 1; //保证最后一次为gap = 1的插入排序
       for (i = 0; i < n - gap; i++) {
           int end = i;
           int tmp = a[end + gap];
           while (end >= 0 && a[end] > tmp) {
               a[end + gap] = a[end];
               end -= gap;
           }
           a[end + gap] = tmp;
       }
   }
}
void SelectSort(int* a,int n){
    int begin = 0,end = n-1;
    while(begin<end) {
        //每次选一个最大的和最小的，放到相应的位置
        int i, max, min;
        max = min = begin;
        for (i = begin; i <= end; ++i) {
            if (a[i] < a[min])
                min = i;
            if (a[i] > a[max])
                max = i;
        }
        Swap(&a[begin], &a[min]);
        //判断最大元素的位置是否发生变化               ？？？？？？？？？？
        if(max == begin)
            max = min;
        Swap(&a[end], &a[max]);
        ++begin;
        --end;
    }
}
void BubbleSort(int* a,int n){
    int i;
    int flag = 0;
    for(i = n-1;i >= 0; --i){
        for(int j = 0;j <= i; ++j){
            if(a[j] > a[j+1]) {
                Swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
//三数取中法:保证快速排序每次的划分均衡,从而保证快速排序的性能
int getMid(int* a,int left,int right){
    int mid = left + (right - left) / 2;
    if(a[mid] > a[left]){
        if(a[mid] < a[right])
            return mid;
        else{
            // mid > left,right
            if(a[left] > a[right])
                return left;
            else
                return right;
        }
    }else{
        // mid <= left
        if(a[left]<a[right])
            return left;
        else{
            //left >= right,mid
            if(a[mid] > a[right])
                return mid;
            else
                return right;
        }
    }
}
int PartSort(int* a,int left,int right) {
    //三数取中
    int mid = getMid(a,left,right);
    Swap(&a[mid],&a[left]);
    //快排的一次排序：确定基准值的位置
    int key = a[left];
    int start = left;
    //寻找大小元素交换
    while (left < right) {
        //先从右边找小于key的值
        while (left < right && a[right] >= key)
            --right;
        //从左边找大于key的值
        while (left < right && a[left] <= key)
            ++left;
        Swap(&a[left], &a[right]);
    }
    //key的位置确定:left right相遇的位置
    Swap(&a[start],&a[left]);
    return left;
}
//挖坑法
int PartSort2(int* a,int left,int right){
    int mid = getMid(a,left,right);
    Swap(&a[mid],&a[left]);
    int key = a[left];
    while(left < right){
        //从右边找小的
        while (left < right && a[right] >= key)
            --right;
        //填坑
        a[left] = a[right];
        //从左边找大的
        while (left < right && a[left] <= key)
            ++left;
        //填坑
        a[right] = a[left];
    }
    //存放key
    a[left] = key;
    return left;
}
void QuickSort(int* a,int left,int right){
    if(left >= right)
        return;
    //小区间优化：小区间不调用递归
    if(right - left + 1<5){
        InsertSort(a + left,right - left + 1);
    } else {
        int mid = PartSort2(a, left, right);
        QuickSort(a, left, mid - 1);
        QuickSort(a, mid + 1, right);
    }
}
void _MergeSort(int* a,int left,int right,int* tmp){
    //归并
    int begin1,end1,begin2,end2; //begin1-end2 -->left - right
    int tmpindex = begin1;
    while (begin1 <= end1 && begin2 <= end2){
        if(a[begin1] <= a[begin2]){
            tmp[tmpindex++] = a[begin1++];
        } else{
            tmp
        }
    }
}

void PrintArray(int* a,int n){
    int i;
    for(i = 0;i < n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Test(){
    int a[] = {3,4,5,1,6,7,9,8,2,10};
    PrintArray(a,10);
    QuickSort(a,0, sizeof(a)/ sizeof(a[0]) - 1);
    PrintArray(a,10);
}
void test2(){
    srand(time(NULL));
    int i,num = 100000;
    int* arr1 = (int*)malloc(sizeof(int)* num);
    int* arr2 = (int*)malloc(sizeof(int)* num);
    int* arr3 = (int*)malloc(sizeof(int)* num);
    int* arr4 = (int*)malloc(sizeof(int)* num);
    int* arr5 = (int*)malloc(sizeof(int)* num);
    for(i = 0;i < num;++i){
        arr1[i] = rand();
    }
    memcpy(arr2,arr1, sizeof(int)*num);
    memcpy(arr3,arr1, sizeof(int)*num);
    memcpy(arr4,arr1, sizeof(int)*num);
    memcpy(arr5,arr1, sizeof(int)*num);

    size_t begin1,end1,begin2,end2,begin3,end3,begin4,end4,begin5,end5;

    begin1 = clock();
    InsertSort(arr1,num);
    end1 = clock();
    printf("InsertSort = %d\n",end1 - begin1);


    begin2 = clock();
    ShellSort(arr2,num);
    end2 = clock();
    printf("ShellSort = %d\n",end2 - begin2);

    /*
    begin3 = clock();
    SelectSort(arr3,num);
    end3 = clock();
    printf("SelectSort = %d\n",end3 - begin3);

    begin4 = clock();
    BubbleSort(arr4,num);
    end4 = clock();
    printf("BubbleSort = %d\n",end4 - begin4);
    */

    begin5 = clock();
    QuickSort(arr5,0,num - 1);
    end5 = clock();
    printf("QuickSort = %d\n",end5 - begin5);
}
int main(){
    Test();
    //test2();
    return 0;
}
