#include <stdio.h>
#include <string.h>
struct employee {
    char name[30];
    char dob[15];
    char dep[30];
    int employee_id;
    int salary;
};
struct employee detail[100]; 
int employee_count = 0; 

void addEmployee() {
    if (employee_count >= 100) {
        printf("Employee list is full! Cannot add more employees.\n");
        return;
    }
    printf("ENTER THE NAME OF EMPLOYEE: ");
    getchar(); 
	gets(detail[employee_count].name);
    printf("ENTER THE DATE OF BIRTH (DD/MM/YYYY): "); 
    gets(detail[employee_count].dob);
    printf("ENTER THE DEPARTMENT OF EMPLOYEE: "); 
    gets(detail[employee_count].dep);
    printf("ENTER THE EMPLOYEE_ID OF EMPLOYEE: ");
    scanf("%d", &detail[employee_count].employee_id);
    printf("ENTER THE SALARY OF EMPLOYEE: ");
    scanf("%d", &detail[employee_count].salary);

    employee_count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (employee_count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nList of Employees:\n");
    for (int i = 0; i < employee_count; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", detail[i].name);
        printf("Date of Birth: %s\n", detail[i].dob);
        printf("Department: %s\n", detail[i].dep);
        printf("Employee ID: %d\n", detail[i].employee_id);
        printf("Salary: %d\n\n", detail[i].salary);
    }
}

void deleteEmployee() {
    if (employee_count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int id, found = 0;
    printf("Enter the Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (detail[i].employee_id == id) {
            found = 1;
            // Shift remaining employees to the left
            for (int j = i; j < employee_count - 1; j++) {
                detail[j] = detail[j + 1];
            }
            employee_count--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    int select;

    while (1) {
        printf("\n1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display all Employees\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

