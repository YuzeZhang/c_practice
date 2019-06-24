
#include<stdio.h>
#include<stdlib.h>
int main(){
	int ch;
	int checksum;
	while((ch = getchar())!=EOF){
		putchar(ch);
		checksum+=ch;
	}
	printf("\n%d",checksum);
	return EXIT_SUCCESS;
}
