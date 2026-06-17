#include<stdio.h>
int main()
{
	int i , f=1 , limit ;
	printf("enter the limit :");
	scanf("%d",&limit);
	if(limit>=0)
	{
		for(i=1;i<=limit;i++)
		{
			f=f*i;
			printf("%d! = %d\n",i ,f);
		}
	}
	else
	{
		printf("enter the positive number");
	}
}
