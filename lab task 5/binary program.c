#include<stdio.h>
int main()
{
	int num , i ;
	printf("enter the number ");
	scanf("%d",&num);
	if (num!=0)
	{
		i+=1;
		num =num&(num-1);
	}
		if (num!=0)
	{
		i+=1;
		num =num&(num-1);
	}
		if (num!=0)
	{
		i+=1;
		num =num&(num-1);
	}
		if (num!=0)
	{
		i+=1;
		num =num&(num-1);
	}
		if (num!=0)
	{
		i+=1;
		num =num&(num-1);
	}
	printf("number reprents 1s are %d",i);
}
