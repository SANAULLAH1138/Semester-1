#include<stdio.h>
int main()
{
	int p , r , t , si ;
	printf("enter the  P=principal_amount b/w (Rs:100 to Rs:1000000):\n");
	scanf("%d",&p);
	printf("enter the R=rate_of_interset b/w( 5 to 10):\n");
	scanf("%d",&r);
	printf("enter the T=time_period b/w(1year to 10 years): \n");
	scanf("%d",&t);
	si=p*r*t;
	printf("%d the simple interest is : ",si);
}
