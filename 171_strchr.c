//
// Created by zeno on 2019/9/6.
//

#include <stdio.h>
#include <assert.h>
const char* Strchr(const char*str,int character){
    assert(str&&character);
    char* sign = str;
    while(sign!='\0'){
        if(*sign==character){
            return sign;
        }
        sign++;
    }
    return NULL;
}
int main(){
    char str[] = "This is a sample string";
    char* pch;
    printf("Looking for the 's' character in \"%s\"...\n",str);
    pch = Strchr(str,'s');
    while (pch!=NULL){
        printf("found at %d\n",pch-str+1);
        pch = Strchr(pch+1,'s');
    }
    return 0;
}
