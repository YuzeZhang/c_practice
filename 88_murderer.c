#include<stdio.h>
int main(void)
{
	for(char murderer='A';murderer<='D';++murderer){
		if ((murderer!='A')+(murderer=='C')+(murderer=='D')+(murderer!='D')==3) {
			printf("凶手是%c\n",murderer);
		}
	}
	return 0;
}
