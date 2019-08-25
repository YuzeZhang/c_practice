//
// Created by zeno on 2019/8/25.
//

#include <stdio.h>
int positive_reverse(int num){
    int arr[1024] = {0};
    int count = 0;
    for(int i = 0;num != 0;++i,++count){
        arr[i] = num%10;
        num/=10;
    }
    for(int j = count - 1;j>=0;--j){
        printf("%d ",arr[j]);
    }
    printf("\n");
    int i = 0,j = count-1;
    for(;j>=0;--j,++i){
        if(arr[i] == arr[j]){
            continue;
        }
        break;
    }
    if(j<0){
        return 1;
    }
    return 0;
}
int main(){
    if(positive_reverse(1211321)){
        printf("yes");
    } else{
        printf("no");
    }
    return 0;
}
