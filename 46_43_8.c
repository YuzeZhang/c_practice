#include<stdio.h>
#include<math.h>
int main(){
	printf("水仙花数有:");
	for(int i=100;i<1000;i++){
		int hundred,ten,digit;
		hundred = i/100;
		ten = (i-hundred*100)/10;
		digit = i-hundred*100-ten*10;
		if(pow(hundred,3)+pow(ten,3)+pow(digit,3)==i){
			printf("%d\t",i);
		}
	}
	return 0;
}                                                                  
