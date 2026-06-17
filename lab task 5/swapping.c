#include<stdio.h>
int main()
{
	int a , b , temp ;
	printf("enter the value of a ");
	scanf("%d",&a);
	printf("enter the value of b ");
	scanf("%d",&b);
	printf("after swapping \n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	 temp=a ;
	 a = b ;
	 b = temp ;
	 printf("before swapping \n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
}
