#include <stdio.h>
void mul_list(int row,int rank){
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= rank; j++) {
			printf("%d*%d=%d\t\t",i,j,i*j);
			if (j==rank) {
				printf("\n");
			}
		}
		if (i==row) {
			printf("\n");
		}
	}
}
int main(){
	int row,rank;
	printf("请输入乘法口诀表的行数:");
	scanf("%d", &row);
	printf("请输入乘法口诀表的列数:");
	scanf("%d", &rank);
	mul_list(row,rank);
	return 0;
}
