#include<stdio.h>
int main()
{
	int sum=0,i;
	printf("enter the limit :");
	scanf("%d",&i);
	int limit[i];
	for(int j=0;j<i;j++)
	{
		printf("Enter the %d value: ",j+1);
		scanf("%d",&limit[j]);
		sum+=limit[j];
		
	}
	printf("\nSUM IS = %d\n",sum);
}
