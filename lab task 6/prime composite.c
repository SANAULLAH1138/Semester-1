   #include<stdio.h>
#include<conio.h>
int main() 
{
	int prime , composite , count = 0 ;
	printf("enter the value: ");
	scanf("%d",&prime); 
	for(int i=1; i<=prime; i++)
	{
	
		if(prime%i==0)
		{
		count++;
		}
	}
	if(count==2)
	{ 
	printf("this is a prime number ");
	}
	else
	{
		printf("this is a composite number ");
	}
}
