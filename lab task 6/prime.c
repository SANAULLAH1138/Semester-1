#include<stdio.h>

int main()
{
    int n, i, count = 0;
    int a = 0, b = 1, c;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            count++;
        }
    }

    if(count == 2) 
    {
        printf("%d is a prime number.\n", n);
        printf("Fibonacci sequence up to %d terms:\n", n);
        for(i = 1; i <= n; i++)
        {
            printf("%d ", a);
            c = a + b; 
            a = b;
            b = c;
        }
        printf("\n");
    }
    else
    {
        printf("%d is a composite number.\n", n);
    }

    return 0;
}


