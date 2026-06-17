#include<stdio.h>
int main()
{
     int i , j , n ;
     printf("enter the value of n :");
     scanf("%d",&n);
     for(i=0;i<n;i++)
   {
       for(j=0;j<n-1;j++)
       {
           printf(" ");
       }
         for(j=1;j<=i;j++)
       {
          printf("%d",j);
       }
         for(j=i-1;j>=1;j--)
       {
           printf("%d",j);

        }
           printf("\n");
    }
}
