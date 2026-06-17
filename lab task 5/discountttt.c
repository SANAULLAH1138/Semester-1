#include <stdio.h>

int main() {
    float purchaseAmount;
    int membership;
    printf("Enter the purchase amount: ");
    scanf("%f", &purchaseAmount); 
    printf("Enter the membership (1 for member, 0 for not a member): ");
    scanf("%d", &membership); 
    const char *discountEligibility = (purchaseAmount > 100 && membership == 1) ? "eligible" : "not eligible";
    printf("The customer is %s for the discount.\n", discountEligibility); 
    return 0;
}

