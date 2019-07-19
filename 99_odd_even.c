//
// Created by handsomezyz on 2019/7/19.
//
#include <stdio.h>
void swap(int* a,int* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
void odd_even(int arr[],int size){
    int temp,start=0;
    int end = size-1;
    while (start<end){
        if((arr[start]&1==1)){
            ++start;
            continue;
        }
        swap(&arr[start],&arr[end]);
        --end;
    }
    for (int i = 0; i < size;++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/ sizeof(arr[0]);
    odd_even(arr,size);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
