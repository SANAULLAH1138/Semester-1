#include <stdio.h>
int main() {
    int arr[12], pairSum[6], i;
    printf("Enter 12 elements:\n");
    for(i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 6; i++) {
        pairSum[i] = arr[2*i] + arr[2*i+1];
    }
    printf("Pair Sum Array:\n");
    for(i = 0; i < 6; i++) {
        printf("%d ", pairSum[i]);
    }

    return 0;
}
