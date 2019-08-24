//
// Created by zeno on 2019/8/24.
//

#include <stdio.h>
char* del_str(char* destination,const char* source){
    if(destination==NULL||source==NULL){
        return destination;
    }
    int i;
    for(i = 0;destination[i]!='\0';++i){
        int j = 0;
        for(;source[j]!='\0';++j){
            if(destination[i]!=source[j]){
                continue;
            }
            break;
        }
        if(source[j]!='\0'){
            for(int k = i;destination[k]!='\0';++k){
                destination[k] = destination[k+1];
            }
            --i;
        }
    }
    ++i;
    if(destination[i]=='\0'){
        printf("%s\n",destination);
    }
}
int main(){
    char destination[] = "They are studeeeeeents";
    char source[] = "aeiou";
    char* result = del_str(destination,source);
}
