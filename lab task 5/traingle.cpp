#include <stdio.h>

int main() {
    int i, j, rows;

    // Number of rows for the triangle
    rows = 5;

    // Outer loop for each row
    for (i = 1; i <= rows; i++) {
        // Print leading spaces
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Print stars for the triangle
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

