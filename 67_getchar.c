#include<stdio.h>
int main(){
	char ch;
	while (ch!=EOF) {
		ch = getchar();
		if (ch>='a'&&ch<='z') {
			printf("%c\n",ch-32);
		}
		if (ch>='A'&&ch<='Z') {
			printf("%c\n",ch+32);
		}
	}
	return 0;
}
