#include<stdio.h>
void move(char a,char b){
printf("%c------->%c\n",a,b);
}
void hanoit(int n,char a,char b,char c){
	if (n==1) {
		move(a,c);
	}else{
		hanoit(n-1,a,c,b);
		move(a,c);
		hanoit(n-1,b,a,c);
	}
}
int main(){
	int n;
	printf("请输入盘子的数量:");
	scanf("%d", &n);
	hanoit(n,'A','B','C');
	return  0;
}
