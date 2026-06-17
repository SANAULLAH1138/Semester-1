#include<stdio.h>
int sum(int num)
{

if(num==0)
{
	return 0;
}
return (num%10) +sum (num/10);
}
int main()
{
	int n ;
	printf("ENTER THE VALUE OF N : ");
	scanf("%d",&n);
	int result=sum(n);
	printf("%d",result);
	
}
