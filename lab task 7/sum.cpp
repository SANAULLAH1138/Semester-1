#include<stdio.h>
int main()
{
	int i,sum=0 ;
	printf("enter the limit :");
	scanf("%d",&i);
	int limit[i];
	for( int j=0;j<i;j++)
	{
		printf("ENTER THE VALUE \n");
		scanf("%d",&limit[j]);
		sum+=limit[j];
	
	}
		printf("SUM IS == %d ",sum);
	
}
