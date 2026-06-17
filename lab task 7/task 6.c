#include<stdio.h>
int main()
{
	int limit[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int i , maxsize , minsize;
	maxsize=limit[28];
	minsize=limit[0];
	for(i=0;i<30;i++)
	{
	      if(limit[i]>maxsize)
		  {
		  	maxsize=limit[i];
		  	printf("THE MAXIMUM VALUE IS :%d \n",maxsize);
		  }	
	}
	
	
	for(i=0;i<30;i++)
	{
		if(limit[i]<minsize)
		{
			minsize=limit[i];
		}
	}
	printf("THE MINIMUM VALUE IS  %d ",minsize);
}
