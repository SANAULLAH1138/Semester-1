#include <stdio.h>
int main() 
{
	int i , j ;
    int matrix[3][3];
    int rowSum[3] = {0, 0, 0};
    int colSum[3] = {0, 0, 0};
    printf("Enter the scores for a 3x3 matrix (3 participants and 3 activities):\n");
    for ( i = 0; i < 3; i++) 
	{
        for ( j = 0; j < 3; j++) 
		{
            printf("Score for participant %d in activity %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    for ( i = 0; i < 3; i++) 
   {
        for ( j = 0; j < 3; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }
    printf("\nSum of scores for each participant:\n");
    for ( i = 0; i < 3; i++)
    {
        printf("Participant %d total score: %d\n", i + 1, rowSum[i]);
    }
    printf("\nSum of scores for each activity:\n");
    for ( j = 0; j < 3; j++) 
	{
        printf("Activity %d total score: %d\n", j + 1, colSum[j]);
    }
}

