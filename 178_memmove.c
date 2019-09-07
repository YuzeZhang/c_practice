//
// Created by zeno on 2019/9/7.
//

#include <stdio.h>
#include <assert.h>
void* Memmove(void* destination,const void* source,size_t num){
    assert(destination&&source);
    if(destination<source){
        //如果dest<src 正序拷贝
        char* d = (char*)destination;
        char* s = (char*)source;
        while (num){
            *d++ = *s++;
            --num;
        }
    }else{
        //如果dest>src 倒序拷贝
        char* d = (char*)destination+num-1;
        char* s = (char*)source+num-1;
        while (num){
            *d-- = *s--;
            --num;
        }
    }
}
int main(){
    char str[] = "memmove can be very useful...";
    Memmove(str+20,str+15,11);
    puts(str);
    return 0;
}
