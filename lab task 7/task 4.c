#include<stdio.h>
int main()
{
	int limit[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int sum=0;
	int i;
	for(i=0;i<=15;i++)
	{
		sum+=limit[i];
		
	}
	printf("SUM OF 15 NUMBERS IS == %d \n",sum);
}
