#include<stdio.h>
int main()
{ 
   int n;
   do
   { 
      printf("Enter the number: ");
      scanf("%d", &n);
      if(n > 0)
      {
          printf("<<  HELL_YEAH   >>\n");
      }
      else
      {
          printf("Invalid input! Please enter a positive number.\n");
      }
   }
   while(n <= 0);
   
   return 0;	
}

