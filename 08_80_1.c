#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double p,r;
	int n;
	r=0.1;
	n=10;
	p=pow(1+r,n);
	printf("%f",p);
	return EXIT_SUCCESS;
}
