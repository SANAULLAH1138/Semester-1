
#include <stdio.h>
#include <stdlib.h>

void collectFees(int numPoints, double *fees) {
    for (int i = 0; i < numPoints; i++) {
        double fee;
        printf("Enter the fee for point %d: ", i + 1);
        scanf("%lf", &fee);
        while (fee < 0) {
            printf("Error: Fee cannot be negative. Please enter a valid fee for point %d: ", i + 1);
            scanf("%lf", &fee);
        }
        fees[i] = fee;
    }
}
double TotalProfit(int numPoints, double *fees) {
    double totalProfit = 0.0;
    for (int i = 0; i < numPoints; i++) {
        totalProfit += fees[i];
    }
    return totalProfit;
}
int main() {
    int numPoints;
    printf("Enter the total number of points : ");
    scanf("%d", &numPoints);
    while (numPoints <= 0) {
        printf("Error: Number of points must be positive. Please enter again: ");
        scanf("%d", &numPoints);
    }

    double *fees = (double *)malloc(numPoints * sizeof(double));
    collectFees(numPoints, fees);
    double totalProfit = TotalProfit(numPoints, fees);
    printf("Total profit generated: %.2f\n", totalProfit);
    free(fees);
    return 0;
}

