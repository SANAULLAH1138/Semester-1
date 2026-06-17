#include<stdio.h>
int main()
{
	int num;
	printf("enter the number");
	scanf("%d",&num);
	(num&1)==0 ? printf("%d even number \n",num) : printf("%d odd number \n",num);
	
}
