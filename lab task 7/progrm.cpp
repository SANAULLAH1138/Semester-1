#include<stdio.h>
int main()
{
	int i,j;
	printf("ENTER THE VALUE:");
	scanf("%d",&j);
	int limit[j];
	
	for(i=0;i<j;i++)
	{
	
	printf("ENTER %d THE LIMIT  :",i+1);
	scanf("%d",&limit[i]);
	}
}
