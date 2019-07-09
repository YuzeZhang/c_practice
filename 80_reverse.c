#include<stdio.h>
#include<string.h>
char* reverse_string(char* str){
	int len = strlen(str);
	if (len>1) {
		char temp;
		temp = str[0];
		str[0] = str[len-1];
		str[len-1] = '\0';
		reverse_string(str+1);
		str[len-1] = temp;
	}
	return str;
}
int main(){
	char str[10] = {0};
	char ch;
	printf("请输入一个字符串(10个字符以内,以换行符终止):");
	for (int i = 0; i < 10; i++) {
		if ((ch = getchar())!='\n') {
			str[i] = ch;
			continue;
		}
		break;
	}
	printf("字符串元素为:\t");
	puts(str);
	reverse_string(str);
	printf("倒序输出为:\t");
	puts(str);
	return 0;
}
