#include<stdio.h>
int Is_Repeat(int player[5]){
	for (int i = 0; i < 4; ++i) {
		for (int j=i+1;j<5;++j) {
			if (player[i]==player[j]) {
				return 1;
			}
		}
	}
	return 0;
}
int main(void)
{
	int player[5] = {0};//0--A;1--B;2--C;3--D;4--E
	for(player[0]=1;player[0]<=5;++player[0]){
		for(player[1]=1;player[1]<=5;++player[1]){
			for(player[2]=1;player[2]<=5;++player[2]){
				for(player[3]=1;player[3]<=5;++player[3]){
					for(player[4]=1;player[4]<=5;++player[4]){
						// a + b == 1表示a、b两个表达式中有且只有一个成立
						if (((player[1]==2)+(player[0]==3))==1&&((player[1]==2)+(player[4]==4))==1
							&&((player[2]==1)+(player[3]==2))==1&&((player[2]==5)+(player[3]==3))==1
							&&((player[4]==4)+(player[0]==1))==1) {
							if (!Is_Repeat(player)) {
								printf("A:第%d\tB:第%d\tC:第%d\tD:第%d\tE:第%d\t\n",player[0]
										,player[1],player[2],player[3],player[4]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
