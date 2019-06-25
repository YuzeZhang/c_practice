#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int p;
	double r,m;
	double d = 300000;
	p=6000;
	r=0.01;
	m = (log(p/(p-d*r)))/(log(1+r));
	printf("%6.1f",d);
	printf("%6.1f",m);
	return EXIT_SUCCESS;
}
