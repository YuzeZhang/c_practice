//
// Created by zeno on 2019/8/1.
//
#include <stdio.h>
#include <string.h>
// str3表示要替换成的内容
// str2表示要被替换掉的内容
void str_replace(char* p,int n,char* str){
    //p是在整个字符串中出现str2时的字符地址
    //n表示str2的长度
    //str是str3的形参
    int lenofstr;//lenofstr表示str3的长度
    char* tmp;
    lenofstr = strlen(str);
    //如果str3的长度比str2的长度短，则后面的每一个字符往前挪一位
    if(lenofstr<n){
        tmp = p+n;//此时tmp指向替换前str2的后一个字符的地址
        while (*tmp){//当tmp指向的字符不为'\0'时
            *(tmp-(n-lenofstr)) = *tmp;//n-lenofstr表示str2比str3多出的长度,(tmp-(n-lenofstr))指向替换后str3的后一个字符的地址
            //此操作将替换前str2的后一个字符赋值给替换后str3的后一个字符
            tmp++;//通过 ++ 操作将每一个字符提前，直到出现'\0'
        }
    } else if(lenofstr>n){
        tmp = p;
        //使tmp指向'\0'
        while (*tmp){
            tmp++;
        }
        while (tmp>=p+n){
            *(tmp+(lenofstr-n)) = *tmp;
            tmp--;
            //将tmp后(lenofstr-n)个位置的字符赋值为原来tmp指向的字符
            //从后向前一直到p+n处
        }
    }
    strncpy(p,str,lenofstr);
}
int main(){
    char str1[1024] = "abc defgx yz";
    char str2[128] = " ";
    char str3[128] = "%20";
    char* p;
    p = strstr(str1,str2);//找到str1中str2的位置
    while (p){
        str_replace(p,strlen(str2),str3);//每找到一个str2，就用str3替换
        p = p+strlen(str3);//找到后将p置于替换后str3结束的位置
        p = strstr(p,str2);//从新的p的位置开始继续在str1中找下一个str2的位置
        //直到strstr函数在str1中找不到str2，返回NULL
    }
    printf("替换的结果为：%s\n",str1);
    return 0;
}

