#include<stdio.h>
int Strlen(char* str){
	if (*str == '\0') {
		return 0;
	}
	return Strlen(++str)+1;
}
int main(){
	int len;
	char str[100];
	printf("请输入一个字符串:\n");
	fgets(str,100,stdin);
	len = Strlen(str)-1;
	printf("字符串的长度为:%d\n",len);
	return 0;
}
