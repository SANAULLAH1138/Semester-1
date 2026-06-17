
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;      
    int currSize;    
    int capacity;    
} DynamicArray;
DynamicArray* createDynamicArray() {
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->capacity = 1;
    arr->currSize = 0;
    arr->array = (int*)malloc(arr->capacity * sizeof(int));
    return arr;
}
void resizeArray(DynamicArray* arr) {
    arr->capacity *= 2; 
    arr->array = (int*)realloc(arr->array, arr->capacity * sizeof(int));
}
void insertAt(DynamicArray* arr, int index, int value) {
    if (index < 0 || index > arr->currSize) {
        printf("Index out of bounds.\n");
        return;
    }
    if (arr->currSize == arr->capacity) {
        resizeArray(arr); 
    }
    for (int i = arr->currSize; i > index; i--) {
        arr->array[i] = arr->array[i - 1]; 
    }
    arr->array[index] = value; 
    arr->currSize++;
}
void deleteAt(DynamicArray* arr, int index) {
    if (index < 0 || index >= arr->currSize) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < arr->currSize - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }
    arr->currSize--;
}
void printArray(DynamicArray* arr) {
    for (int i = 0; i < arr->currSize; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}
void freeDynamicArray(DynamicArray* arr) {
    free(arr->array);
    free(arr);
}
int main() {
    DynamicArray* arr = createDynamicArray();
    insertAt(arr, 0, 10);  
    insertAt(arr, 1, 20);  
    insertAt(arr, 1, 15); 
    
    printf("Array after insertions: ");
    printArray(arr);       
    deleteAt(arr, 1);      
    
    printf("Array after deletion: ");
    printArray(arr);       

    freeDynamicArray(arr); 

    return 0;
}

