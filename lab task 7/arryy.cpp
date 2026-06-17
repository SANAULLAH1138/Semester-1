#include<stdio.h>
int main()
{
	int i , temp;
	printf("ENTER THE VALUE :");
	scanf("%d",&i);
	int limit[i];
	printf("BEFORE REARRANGING \n");
	for(int j=0;j<i;j++)
	{
		
		printf("ENTER VALUE  ");
		scanf("%d",&limit[j]);
	
	}
	printf("AFTER REARRANGING \n");
	for(int j=0;j<i;j++)
	{
	
		limit[j]=temp;
		temp=limit[i];
		limit[i]=limit[j];
		
		printf("%d",&limit[j]);
		
}
}
