//
// Created by zeno on 2019/9/2.
//

#include <stdio.h>
void adjustment(int* arr,int len){
    int temp;
    for (int i = 0; i < len; ++i) {
        if(arr[i]%2==0){
            for (int j = i+1; j < len; ++j) {
                if(arr[j]%2!=0){
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    adjustment(arr,len);
    for (int i = 0; i < len; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
