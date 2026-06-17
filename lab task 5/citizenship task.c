#include<stdio.h>
int main()
 {
    char citizen;
    int age;
    printf("Enter citizenship (Y for yes, N for no): ");
    scanf(" %c", &citizen);
    
    printf("Enter the age: ");
    scanf("%d", &age);
    if(citizen == 'Y' || citizen == 'y') {
        printf("You are Pakistani:\n");
        if(age >= 18) {
            printf("Eligible for vote\n");
        } else {
            printf("Not eligible for vote (under 18)\n");
        }
    } else {
        printf("Not eligible for vote (not a Pakistani citizen)\n");
    }

    return 0;
}
