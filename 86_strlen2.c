#include<stdio.h>
int Strlen(char* str){
	int i = 0;
	while (*(str + i)!= '\0') {
		i++;
	}
	return i;
}
int main(){
	char str[]= "1234";
	printf("%d\n",Strlen(str));
	return 0;
}
