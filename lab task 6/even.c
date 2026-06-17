#include<stdio.h>
int main()
{
	int  n;
	printf("enter the number :");
	scanf("%d",&n);
	while(n>=1)
	{
		if(n%2==0)
		{
			printf(" %d ",n);
			n=n-2;
		}
		else
	{
		printf("enter positive number");
	}
	}

}

