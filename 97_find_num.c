//
// Created by handsomezyz on 2019/7/17.
//
#include <stdio.h>
int main(){
    int arr[] = {1,1,2,3,4,5,3,5,4};
    int len = sizeof(arr)/ sizeof(arr[0]);
    int ret =arr[0];
    for (int i = 1; i < len; ++i) {
        ret^=arr[i];
    }
    printf("%d在数组中只出现了一次",ret);
    return 0;
}
