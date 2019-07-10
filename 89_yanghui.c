#include<stdio.h>
#define SIZE 10 //设置杨辉三角的规格
int main(void)
{
	int triangle[SIZE][SIZE] = {0};
	//三角每列第一个和行列相同时设为1 
	for (int i = 0; i < SIZE; ++i) {
		triangle[i][0] = 1;
		triangle[i][i] = 1;
	}
	//根据杨辉三角规律赋值
	for(int i=2;i<SIZE;++i){
		for(int j=1;j<i;++j){
			triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
		}
	}
	//打印杨辉三角
	for(int row = 0;row<SIZE;++row){
		for(int col=0;col<=row;++col){
			printf("%d ",triangle[row][col]);
		}
		printf("\n");
	}
	return 0;
}
