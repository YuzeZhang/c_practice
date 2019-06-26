#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 100
#define MAX 200
int main(){
	int judge=0;
	printf("100-200之间的素数有：\n");
	for(int i=MIN;i<=MAX;i++){	
		judge=0;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				judge = 1;
			}
		}
		if(judge==0){
			printf("%d\t",i);
			}
	
	}
	printf("\n");
	return 0;
}
