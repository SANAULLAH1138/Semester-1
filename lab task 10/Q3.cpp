#include <stdio.h>
#include <string.h>
#define MAX_CARS 100
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};
void inputCarDetails(struct Car *car) 
{
    printf("Enter car make: ");
    scanf(" %[^\n]", car->make); 

    printf("Enter car model: ");
    scanf(" %[^\n]", car->model); 

    printf("Enter car year: ");
    scanf("%d", &car->year);

    printf("Enter car price: ");
    scanf("%f", &car->price);

    printf("Enter car mileage: ");
    scanf("%f", &car->mileage);
}
void displayCar(struct Car *car) 
{
    printf("Make: %s\n", car->make);
    printf("Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
    printf("Price: %.2f\n", car->price);
    printf("Mileage: %.2f\n", car->mileage);
}
void displayAllCars(struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }
     printf("\nList of Available Cars:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        displayCar(&cars[i]);
        printf("---------------------------------------------------\n");
    }
}
void searchCars(struct Car cars[], int carCount, const char *searchTerm) {
    int found = 0;

    for (int i = 0; i < carCount; i++) {
        if (strstr(cars[i].make, searchTerm) != NULL || strstr(cars[i].model, searchTerm) != NULL) {
            if (!found) {
                printf("\nSearch Results:\n");
                printf("---------------------------------------------------\n");
                found = 1;
            }
            printf("Car %d:\n", i + 1);
            displayCar(&cars[i]);
            printf("---------------------------------------------------\n");
        }
    }

    if (!found) {
        printf("No cars found matching your search term.\n");
    }
}
int showMenu() {
    int choice;
    printf("\nCar Dealership Menu:\n");
    printf("1. Add a new car\n");
    printf("2. Display all available cars\n");
    printf("3. Search for cars by make or model\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() 
{
    struct Car cars[MAX_CARS]; 
    int carCount = 0;
    int choice;
    char searchTerm[50];

    while (1) {
        choice = showMenu(); 

        switch (choice) {
            case 1:
                if (carCount < MAX_CARS) {
                    inputCarDetails(&cars[carCount]);  
                    carCount++;
                } else {
                    printf("Car dealership is full. Cannot add more cars.\n");
                }
                break;

            case 2:
                displayAllCars(cars, carCount);  
                break;

            case 3:
                printf("Enter make or model to search: ");
                scanf(" %[^\n]", searchTerm);  
                searchCars(cars, carCount, searchTerm);  
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

