#include <stdio.h>
int main() {
    int arr[10], i, firstElement;
    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    firstElement = arr[0];
    for(i = 0; i < 9; i++) 
	{
        arr[i] = arr[i+1];
    }
    arr[9] = firstElement;
    printf("Shifted Array:\n");
    for(i = 0; i < 10; i++) 
	{
        printf("%d ", arr[i]);
    }

    return 0;
}
