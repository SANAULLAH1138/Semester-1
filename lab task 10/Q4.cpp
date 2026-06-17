#include <stdio.h>
#include <string.h>
#define MAX_PACKAGES 10
typedef struct {
    char name[50];
    char destination[50];
    int duration;
    float cost;
    int available_seats;
} TravelPackage;
void displayPackages(TravelPackage packages[], int numPackages);
void bookPackage(TravelPackage packages[], int numPackages, const char *packageName);

int main() {
    TravelPackage packages[MAX_PACKAGES];
    int numPackages = 0;
    int choice;
    strcpy(packages[numPackages].name, "Beach Vacation");
    strcpy(packages[numPackages].destination, "Hawaii");
    packages[numPackages].duration = 7;
    packages[numPackages].cost = 1200.00;
    packages[numPackages].available_seats = 10;
    numPackages++;

    strcpy(packages[numPackages].name, "Adventure Tour");
    strcpy(packages[numPackages].destination, "Swiss Alps");
    packages[numPackages].duration = 5;
    packages[numPackages].cost = 1800.00;
    packages[numPackages].available_seats = 5;
    numPackages++;

    strcpy(packages[numPackages].name, "Cultural Experience");
    strcpy(packages[numPackages].destination, "Japan");
    packages[numPackages].duration = 10;
    packages[numPackages].cost = 2200.00;
    packages[numPackages].available_seats = 2;
    numPackages++;

    while(1) 
	{
        printf("\nWelcome to the Travel Agency!\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Travel Package\n");
        printf("3. Exit\n");
        printf("Please choose an option (1/2/3): ");
        scanf("%d", &choice);
        
        switch(choice) 
		{
            case 1:
            
                displayPackages(packages, numPackages);
                break;
            case 2:
                
                {
                    char packageName[50];
                    printf("Enter the name of the package you want to book: ");
                    getchar();  
                    fgets(packageName, 50, stdin);
                    packageName[strcspn(packageName, "\n")] = '\0'; 

                    bookPackage(packages, numPackages, packageName);
                }
                break;
            case 3:
                printf("Thank you for visiting the Travel Agency!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
void displayPackages(TravelPackage packages[], int numPackages) {
    printf("\nAvailable Travel Packages:\n");
    for(int i = 0; i < numPackages; i++) {
        printf("Package Name: %s\n", packages[i].name);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n", packages[i].available_seats);
        printf("------------------------------\n");
    }
}
void bookPackage(TravelPackage packages[], int numPackages, const char *packageName) {
    int found = 0;

    for(int i = 0; i < numPackages; i++) {
        if(strcmp(packages[i].name, packageName) == 0) {
            found = 1;
            if(packages[i].available_seats > 0) {
                packages[i].available_seats--;
                printf("Seat successfully booked for the %s package.\n", packages[i].name);
            } else {
                printf("Sorry, no seats available for the %s package.\n", packages[i].name);
            }
            break;
        }
    }

    if(!found) {
        printf("Package '%s' not found.\n", packageName);
    }
}

