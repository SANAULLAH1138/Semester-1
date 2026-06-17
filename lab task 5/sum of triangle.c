#include<stdio.h>

int main() {
    float a, b, c, sum;
    printf("enter the value of A ");
    scanf("%f", &a);
    printf("enter the value of B ");
    scanf("%f", &b);
    printf("enter the value of C ");
    scanf("%f", &c);

    sum = a + b + c;
    printf("sum of triangle is %f\n", sum);

    if (sum >= 0) {
        printf("positive values\n");
        if (sum == 180)
            printf("triangle is valid");
        else
            printf("invalid triangle");
    } else {
        printf("you put negative values");
    }

    return 0;
}
