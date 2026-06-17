#include<stdio.h>
int main()
{
    float per;
    printf("Enter the percentage: ");
    scanf("%f", &per);

    (per >= 90) ? printf("GRADE - A") :
    (per >= 80 && per < 90) ? printf("GRADE - B") :
    (per >= 70 && per < 80) ? printf("GRADE - C") :
    (per >= 60 && per < 70) ? printf("GRADE - D") :
    printf("FAIL");

    return 0;
}

