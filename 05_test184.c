#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000
int main(){
	char input[MAX_LEN];
	int len;
	char longest[MAX_LEN];
	int longest_len=-1;
	while(fgets(input,MAX_LEN,stdin) != NULL){
		len = strlen(input);
		if (len>=longest_len){
			longest_len=len;
			strcpy(longest,input);
		}
	if(longest>=0)
		puts(longest);
	return EXIT_SUCCESS;
	}
	
}
