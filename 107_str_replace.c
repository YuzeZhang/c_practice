//
// Created by zeno on 2019/8/1.
//
#include <stdio.h>
#include <string.h>
// str3��ʾҪ�滻�ɵ�����
// str2��ʾҪ���滻��������
void str_replace(char* p,int n,char* str){
    //p���������ַ����г���str2ʱ���ַ���ַ
    //n��ʾstr2�ĳ���
    //str��str3���β�
    int lenofstr;//lenofstr��ʾstr3�ĳ���
    char* tmp;
    lenofstr = strlen(str);
    //���str3�ĳ��ȱ�str2�ĳ��ȶ̣�������ÿһ���ַ���ǰŲһλ
    if(lenofstr<n){
        tmp = p+n;//��ʱtmpָ���滻ǰstr2�ĺ�һ���ַ��ĵ�ַ
        while (*tmp){//��tmpָ����ַ���Ϊ'\0'ʱ
            *(tmp-(n-lenofstr)) = *tmp;//n-lenofstr��ʾstr2��str3����ĳ���,(tmp-(n-lenofstr))ָ���滻��str3�ĺ�һ���ַ��ĵ�ַ
            //�˲������滻ǰstr2�ĺ�һ���ַ���ֵ���滻��str3�ĺ�һ���ַ�
            tmp++;//ͨ�� ++ ������ÿһ���ַ���ǰ��ֱ������'\0'
        }
    } else if(lenofstr>n){
        tmp = p;
        //ʹtmpָ��'\0'
        while (*tmp){
            tmp++;
        }
        while (tmp>=p+n){
            *(tmp+(lenofstr-n)) = *tmp;
            tmp--;
            //��tmp��(lenofstr-n)��λ�õ��ַ���ֵΪԭ��tmpָ����ַ�
            //�Ӻ���ǰһֱ��p+n��
        }
    }
    strncpy(p,str,lenofstr);
}
int main(){
    char str1[1024] = "abc defgx yz";
    char str2[128] = " ";
    char str3[128] = "%20";
    char* p;
    p = strstr(str1,str2);//�ҵ�str1��str2��λ��
    while (p){
        str_replace(p,strlen(str2),str3);//ÿ�ҵ�һ��str2������str3�滻
        p = p+strlen(str3);//�ҵ���p�����滻��str3������λ��
        p = strstr(p,str2);//���µ�p��λ�ÿ�ʼ������str1������һ��str2��λ��
        //ֱ��strstr������str1���Ҳ���str2������NULL
    }
    printf("�滻�Ľ��Ϊ��%s\n",str1);
    return 0;
}

