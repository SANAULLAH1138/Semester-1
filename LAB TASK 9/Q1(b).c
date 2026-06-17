#include<stdio.h>
int main() {
    int n;
    int i , j ;
    printf("Enter no of rows: ");
    scanf("%d", &n);
    
    for( i = 0; i <= n; i++){
        for( j = i; j <= n; j++)
            printf(". ");
            
        for( j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }
    for( i = 1; i <= n; i++){
        for( j = 0; j <= i; j++)
            printf(". ");
            
        for( j = i; j <= n; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
