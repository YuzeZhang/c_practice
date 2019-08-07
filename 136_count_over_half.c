//
// Created by zeno on 2019/8/7.
//

#include <stdio.h>
int count_over_half(int arr[],int len){
    for (int i = 0; i <= len - 1; ++i) {
        int count = 0;
        for (int j = 0; j <= len - 1; ++j) {
            if(arr[j]==arr[i]){
                ++count;
            }
        }
        if(count>(len/2)){
            return arr[i];
        }
    }
}
int main(){
    int arr[] = {1,2,3,2,2,2,5,4,2};
    int len = sizeof(arr)/ sizeof(arr[0]);
    int num = count_over_half(arr,len);
    printf("超过数组长度一半的数为%d",num);
}
