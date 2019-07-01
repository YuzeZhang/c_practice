#include<stdio.h>
#include<math.h>
int main(){
	for(int i=4;i<1000;i++)	{
		int a[500];
		for(int j=0;j<500;j++){
			a[j] = 0;
		}
		for(int j=1;j<=(int)(sqrt(i));j++){
			if(i%j==0){
				a[j] = j;
			}
		}
		int sum=0;
		for(int j=0;j<500;j++){
			sum+=a[j];
		}
		if(sum==i){
			printf("%d its factors are",i);
			for(int j=1;j<500;j++){
				if(a[j]!=0){
					printf("%d\t",a[j]);
				}
			}
		}
	}
	return 0;
}
