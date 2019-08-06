//
// Created by zeno on 2019/8/6.
//

#include <stdio.h>
void sort_and_find(int arr[],int K,int len){
    for (int i = 0; i <= len - 1; ++i) {
        int temp;
        for (int j = i+1; j <= len - 1; ++j) {
            if(arr[j]<arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int k = 0; k < K; ++k) {
        printf("%d,",arr[k]);
    }
}
int main(){
    int arr[] = {1,2,54,654,67856,33,21,4,52,4,543,2,234,23765,897,98,7,-11,-22};
    printf("请输入需要查找数组中前多少个最小的数字：");
    int K;
    scanf("%d",&K);
    int len = sizeof(arr)/ sizeof(arr[0]);
    sort_and_find(arr,K,len);
    return 0;
}
