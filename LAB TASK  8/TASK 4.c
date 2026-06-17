#include <stdio.h>
int main() {
    int m, n;
    int i , j ;
    printf("Enter the number of rows : ");
    scanf("%d", &m);
    printf("Enter the number of columns : ");
    scanf("%d", &n);
    int matrix1[m][n], matrix2[m][n], sum[m][n];
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < m; i++) {
        for ( j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for ( j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Resulting Matrix (Sum):\n");
    for (i = 0; i < m; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

