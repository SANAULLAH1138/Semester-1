
#include <stdio.h>
#include <stdlib.h>

void displayArray(float *array, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current numbers in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 4; 
    int size = 0;    
    float *array = (float *)malloc(capacity * sizeof(float));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                if (size >= capacity) {
                    capacity *= 2;
                    array = (float *)realloc(array, capacity * sizeof(float));
                    if (array == NULL) {
                        printf("Memory reallocation failed!\n");
                        return 1; 
                    }
                }
                printf("Enter a floating-point number: ");
                scanf("%f", &array[size]);
                size++;
                break;
            }
            case 2: 
                displayArray(array, size);
                break;
            case 3: { 
                if (size > 0) {
                    size--;
                    printf("Removed the last number. Current size: %d\n", size);
                    if (size <= capacity / 4 && capacity > 4) {
                        capacity /= 2;
                        array = (float *)realloc(array, capacity * sizeof(float));
                        if (array == NULL && size > 0) {
                            printf( "Memory reallocation failed!\n");
                            return 1; 
                        }
                    }
                } else {
                    printf("Array is already empty.\n");
                }
                break;
            }
            case 4: 
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    free(array);
    return 0;
}

