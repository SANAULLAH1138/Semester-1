
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter total number of elements (1 to 100): ");
    scanf("%d", &n);
    if(n<1 || n>100) {
        printf("Invalid number of elements. Please enter a value between 1 and 100.\n");
        return 1;
    }
    int *elements=(int*)calloc(n, sizeof(int));
    if (elements == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i=0;i<n;i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &elements[i]);
    }
    float largest = elements[0]; 
    for (int i = 1; i < n; i++) {
        if (elements[i] > largest) {
            largest = elements[i]; 
        }
    }
    printf("The largest element is: %.2f\n", largest);
    free(elements);
    return 0;
}

