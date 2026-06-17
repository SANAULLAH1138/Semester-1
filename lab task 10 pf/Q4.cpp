#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_CITY_LENGTH 50
#define MAX_FLIGHT_NUMBER_LENGTH 10

typedef struct {
    char flightNumber[MAX_FLIGHT_NUMBER_LENGTH];
    char departureCity[MAX_CITY_LENGTH];
    char arrivalCity[MAX_CITY_LENGTH];
    char departureTime[20];
    char arrivalTime[20];
    int availableSeats;
} Flight;

Flight flights[MAX_FLIGHTS];
int numFlights = 0;

void bookSeat(char* flightNumber) {
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully on flight %s.\n", flightNumber);
            } else {
                printf("No available seats on flight %s.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

void displayAvailableFlights(char* departureCity, char* arrivalCity) {
    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 && strcmp(flights[i].arrivalCity, arrivalCity) == 0) {
            printf("Flight Number: %s\n", flights[i].flightNumber);
            printf("Departure City: %s\n", flights[i].departureCity);
            printf("Arrival City: %s\n", flights[i].arrivalCity);
            printf("Departure Time: %s\n", flights[i].departureTime);
            printf("Arrival Time: %s\n", flights[i].arrivalTime);
            printf("Available Seats: %d\n", flights[i].availableSeats);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No flights available between %s and %s.\n", departureCity, arrivalCity);
    }
}

void updateFlightDetails(char* flightNumber, char* newDepartureTime, char* newArrivalTime, int newAvailableSeats) {
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            strcpy(flights[i].departureTime, newDepartureTime);
            strcpy(flights[i].arrivalTime, newArrivalTime);
            flights[i].availableSeats = newAvailableSeats;
            printf("Flight details updated for flight %s.\n", flightNumber);
            return;
        }
    }
    printf("Flight not found.\n");
}

int main() {
    Flight flight1 = {"AI101", "New York", "Los Angeles", "10:00 AM", "01:00 PM", 50};
    Flight flight2 = {"AI102", "New York", "Chicago", "02:00 PM", "04:00 PM", 30};
    Flight flight3 = {"AI103", "Los Angeles", "Chicago", "03:00 PM", "06:00 PM", 40};
    
    flights[numFlights++] = flight1;
    flights[numFlights++] = flight2;
    flights[numFlights++] = flight3;
    
    bookSeat("AI101");
    displayAvailableFlights("New York", "Los Angeles");
    updateFlightDetails("AI101", "11:00 AM", "02:00 PM", 60);
    displayAvailableFlights("New York", "Los Angeles");
    
    return 0;
}

