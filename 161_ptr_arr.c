//
// Created by zeno on 2019/8/25.
//

#include <stdio.h>
int main(){
    int arr[] = {6,7,8,9,10};
    int* ptr = arr;
    *(ptr++) += 123;
    printf("%d,",*ptr);
    return 0;
}
