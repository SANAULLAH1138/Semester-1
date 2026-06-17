#include<stdio.h>
int main()
{
	int limit[12] , i , pairsum[6];
	printf("enter 12 elements  :\n");
	for(i=0;i<12;i++)
	{
	scanf("%d",&limit[i]);
	}
	for(i=0;i<6;i++)
	{
		pairsum[i]=limit[2*i]+limit[2*i+1];
	}
	printf("SUM ARRAY \n");
	for(i=0;i<6;i++)
	{
		printf(" %d ", pairsum[i]);
	}
}
