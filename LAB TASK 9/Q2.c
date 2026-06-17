#include <stdio.h>
int main() {
    int bolts, nuts, washers;
    printf("Enter the number of bolts: ");
    scanf("%d", &bolts);
    printf("Enter the number of nuts: ");
    scanf("%d", &nuts);
     printf("Enter the number of washers: ");
    scanf("%d", &washers);
    int total_cost = bolts * 5 + nuts * 3 + washers;
    if (nuts < bolts) 
	{
        printf("Check the Order: too few nuts\n");
    }
    if (washers < 2 * bolts) 
	{
        printf("Check the Order: too few washers\n");
    }
    if (nuts >= bolts && washers >= 2 * bolts) 
	{
        printf("Order is OK.\n");
    }
    printf("Total cost: %d cents\n", total_cost);
   return 0;
}
