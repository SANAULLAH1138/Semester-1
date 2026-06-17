#include<stdio.h>
#include<conio.h>

int main() {
    int unit, bill, final;
    float charges;
    
    printf("ENTER THE UNIT ");
    scanf("%d", &unit);

    if(unit <= 30) {
        bill = (unit * 0.60);
        charges = (bill * 15) / 100;
        final = bill + charges;
        printf("UNIT BILL IS %d \n", bill);
        printf("UNIT CHARGES IS %f \n", charges);
        printf("TOTAL BILL IS %d \n", final);
    }
    else if(unit > 30 && unit <= 80) {
        bill = (unit * 0.85);
        charges = (bill * 15) / 100;
        final = bill + charges;
        printf("UNIT BILL IS %d \n", bill);
        printf("UNIT CHARGES IS %f \n", charges);
        printf("TOTAL BILL IS %d \n", final);
    }
    else if(unit > 80 && unit <= 100) {
        bill = (unit * 1.30);
        charges = (bill * 15) / 100;
        final = bill + charges;
        printf("UNIT BILL IS %d \n", bill);
        printf("UNIT CHARGES IS %f \n", charges);
        printf("TOTAL BILL IS %d \n", final);
    }
    else if(unit > 100 && unit <= 120) {
        bill = (unit * 1.60);
        charges = (bill * 15) / 100;
        final = bill + charges;
        printf("UNIT BILL IS %d \n", bill);
        printf("UNIT CHARGES IS %f \n", charges);
        printf("TOTAL BILL IS %d \n", final);
    }
    else if(unit > 120) {
        bill = (unit * 1.60);
        charges = (bill * 15) / 100;
        final = bill + charges;
        printf("UNIT BILL IS %d \n", bill);
        printf("UNIT CHARGES IS %f \n", charges);
        printf("TOTAL BILL IS %d \n", final);
    }
    else {
        printf("invalid unit");
    }

    return 0;
}
