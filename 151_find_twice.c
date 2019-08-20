//
// Created by zeno on 2019/8/22.
//
#include <stdio.h>
int main(){
    int arr[] = {1,3,5,7,1,3,5,9};
    int size = sizeof(arr)/ sizeof(arr[0]);
    printf("没有重复的数字为：");
    for (int i = 0; i <= size-1; ++i) {
        for (int j = 0; j <= size - 1; ++j) {
            if((arr[i]==arr[j])&&(i!=j)){
                break;
            }
            if(j==size-1){
                printf("%d ",arr[i]);
            }
        }
    }
    return 0;
}
