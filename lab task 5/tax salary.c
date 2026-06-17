#include<stdio.h>
int main()
 {
    float taxrate, salary , tax , postTaxSalary;
printf("enter Your Salary");
scanf("%f", &salary);
printf("enter the taxRate (in percentage);");
//user for the tax rate
scanf("%f" ,&taxrate);
//calculate the tax amount
tax=(taxrate/100)*salary;
//afterTaxSalary
 postTaxSalary = salary - tax;
//output
printf("tax to be  paid: %.2f\n", tax);
printf("Salary after tax: %.2f\n",postTaxSalary);
 return 0;
}

