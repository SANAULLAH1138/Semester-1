
#include <stdio.h>
#include <stdlib.h>
int main(){
int* ptr=(int*)malloc(5*sizeof(int));
if(ptr == NULL){
    printf("Memory allocation failed!\n");
    return 1;
    }
    printf("Enter integers:\n");
    for (int i = 0; i < 5; i++) {
    scanf("%d", (ptr + i));
    }
    for (int i = 0; i < 5; i++) {
    printf("%d ", ptr[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
    if(ptr[i]%2 !=0){
    ptr[i]=ptr[i]-1;
    }
    }
    for (int i = 0; i < 5; i++) {
    printf("%d ", ptr[i]);
    }
return 0;
}

