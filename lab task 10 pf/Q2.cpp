#include <stdio.h>

#define MAX_LENGTH 100

int memo[MAX_LENGTH + 1];

int maxPieces(int length) {
    if (length == 0) {
        return 0;
    }
    if (memo[length] != -1) {
        return memo[length];
    }

    int maxCount = -1;

    if (length >= 1) {
        maxCount = (maxCount > maxPieces(length - 1)) ? maxCount : maxPieces(length - 1);
    }
    if (length >= 2) {
        maxCount = (maxCount > maxPieces(length - 2)) ? maxCount : maxPieces(length - 2);
    }
    if (length >= 3) {
        maxCount = (maxCount > maxPieces(length - 3)) ? maxCount : maxPieces(length - 3);
    }

    memo[length] = maxCount + 1;
    return memo[length];
}

int main() {
    int length;
    
    for (int i = 0; i <= MAX_LENGTH; i++) {
        memo[i] = -1;
    }
    
    printf("Enter the length of the rope: ");
    scanf("%d", &length);

    printf("Maximum number of pieces: %d\n", maxPieces(length));
    
    return 0;
}

