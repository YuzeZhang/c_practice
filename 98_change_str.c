//
// Created by handsomezyz on 2019/7/18.
//
#include <stdio.h>
int my_strlen(char* str){
    int len =0;
    while (*str++){//当数组元素不为'\0'(也就是0)的时候++len,此处不能写++*str否则会越界
    ++len;
    }
    return len;
}
void reverse(char* start,char* end){
    //当左下标小于右下标时，交换两下标元素的值
    while (start<end){
        *start = *start^*end;
        *end = *start^*end;
        *start = *start^*end;
        ++start;
        --end;
    }
}
int main(){
    char str[] = "student am I";
    printf("%s\n",str);
    char* p = str;
    char* q = str;
    //先对整个字符串进行倒置
    reverse(str,str+my_strlen(str)-1);
    printf("%s\n",str);
    //对每个单词进行倒置
    while (*p!='\0'&&*q!='\0'){
        if (*q==' '){
            reverse(p,q-1);
            p = q+1;
        }
        q++;
    }
    //由于当q=='\0'时循环就结束了，所以最后一个单词实际上并没有倒置
    //所以再倒置一次最后一个单词
    reverse(p,q-1);
    printf("%s\n",str);
    return 0;
}
