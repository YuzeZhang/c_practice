
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
int main(){
	int ch;
	int line_num=0;
	int at_beginning=TRUE;
	while((ch=getchar())!=EOF){
		if(at_beginning==TRUE){
			at_beginning=FALSE;
			line_num+=1;
			printf("%d",line_num);
		}
		putchar(ch);
		if(ch=='\n'){
		at_beginning=TRUE;}
	}
	return EXIT_SUCCESS;
}
