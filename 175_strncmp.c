//
// Created by zeno on 2019/9/6.
//

#include <stdio.h>
#include <assert.h>
int Strncmp(const char* str1, const char* str2,size_t num){
    assert(str1&&str2);
    while (num&&*str1 == *str2){
        if(*str1=='\0'||*str2=='\0'){
            break;
        }
        ++str1;
        ++str2;
        --num;
    }
    if(num==0){
        return 0;
    }
    return *str1 - *str2;
}
int main(){
    char str[][5] = {"R2D2","C3P0","R2A6"};
    int n;
    puts("Looking for R2 astromech droids...");
    for(n=0;n<3;n++){
        if(Strncmp(str[n],"R2xx",2)==0){
            printf("found %s\n",str[n]);
        }
    }
    return 0;
}
