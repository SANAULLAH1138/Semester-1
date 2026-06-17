#include <stdio.h>
int main() 
{
    int matrix[4][4];
    int i, j;
    printf("Enter the grades for a 4x4 matrix (4 students and 4 subjects):\n");
    for (i = 0; i < 4; i++) 
	{
        for (j = 0; j < 4; j++) 
		{
            printf("Enter grade for student %d in subject %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] < 0) {
                matrix[i][j] = 0;
            }
        }
    }
    printf("\nUpdated grades matrix (negative grades replaced by zero):\n");
    for (i = 0; i < 4; i++) 
	{
        for (j = 0; j < 4; j++) 
		{
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

