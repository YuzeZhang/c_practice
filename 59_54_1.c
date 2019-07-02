#include<stdio.h>
#include<math.h>
int main(){
	int n,a[101];
	for(int i=0;i<=100;i++){
		a[i]=i;
	}
	a[1]=0;
	for(i=2;i<sqrt(100);i++){
		for(int j=i+1;j<=100;j++){
			if(a[i]!=0&&a[j]!=0){
				if(a[j]%a[i]==0){
					a[j]=0;
				}
			}
		}
		printf("\n");
	}
}
