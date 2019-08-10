//
// Created by zeno on 2019/8/20.
//

#include <stdio.h>
char* myString(){
    char buffer[6] = {0};
    char* s = "Hello World!";
    for(int i = 0;i< sizeof(buffer) - 1;i++){
        buffer[i] = *(s+1);
    }
    return buffer;
}
int main(){
    printf("%s,",myString());
    return 0;
}
