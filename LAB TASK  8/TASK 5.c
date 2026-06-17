#include <stdio.h>
#define SIZE 4
int main() {
    int matrix[SIZE][SIZE];
    int col;
    int i , j , temp ;
    printf("Enter the elements of a 4x4 matrix (scores for three teams across three rounds):\n");
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    for ( col = 0; col < SIZE; col++) { 
        for (i = 0; i < SIZE - 1; i++) {
            for ( j = i + 1; j < SIZE; j++) {
                if (matrix[i][col] > matrix[j][col]) {
                 temp = matrix[i][col];
                    matrix[i][col] = matrix[j][col];
                    matrix[j][col] = temp;
                }
            }
        }
    }
    printf("Matrix after sorting each column in ascending order:\n");
    for (i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

