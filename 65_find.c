#include<stdio.h>
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int size;
	size=(sizeof(arr) / sizeof(arr[0]));
	int to_guess;
	printf("请输入要找的数字:");
	scanf("%d", &to_guess);
	int right,left,mid;
	right = size-1;
	left = 0;
	while (1) {
		if (right==left+1) {
			printf("数组中没有%d\n",to_guess);	
			break;
		}
	mid = (left+right)/2;
		if (to_guess<arr[mid]){
			right = mid;
			continue;
		}else if (arr[mid]<to_guess) {
			left = mid;
			continue;
		}else if (arr[mid]==to_guess) {
			printf("要找的数字的下标为:%d\n",mid);
			break;
		}
	}
	return 0;
}
