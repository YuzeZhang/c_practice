#include<stdio.h>
int main(){
	int ten,digit,n=0;
	for(int i=0;i<100;i++){
		if(i==9)
			n++;

		if(i>=10){
			ten = i/10;
			digit = i-ten*10;
			if(ten==9)
				n++;
			if(digit==9)
				n++;
		}
	}
	printf("1-100的整数中出现%d次数字9\n",n);
	return 0;
}                                                       
