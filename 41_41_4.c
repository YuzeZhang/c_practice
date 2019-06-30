#include<stdio.h>
int main(){
	char c;
	int letter= 0,digit=0,space=0,other=0;
	printf("请输入一行字符：");
	while((c = getchar())!='\n'){
		if('a'<=c&&c<='z'||c>='A'&&c<='Z')
			letter++;
		else if(c>='0'&&c<='9')
			digit++;
		else if(c==' ')
			space++;
		else
			other++;
	}
	printf("这行字符中有%d个英文字母，有%d个数字，有%d个空格，有%d个其他字符\n",
	letter,digit,space,other);
	return 0;
}                                                                                          
