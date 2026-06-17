#include <stdio.h>
#include <string.h>
struct Employee {
    int id;            
    char name[50];     
    char department[50]; 
    float salary;      
};
void displayEmployeeDetails(struct Employee emp) 
{
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
}
int main() 
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Enter Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Enter Name: ");
        getchar(); 
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; 
        printf("Enter Department: ");
        fgets(employees[i].department, sizeof(employees[i].department), stdin);
        employees[i].department[strcspn(employees[i].department, "\n")] = '\0'; 
        printf("Enter Salary: ");
        scanf("%f", &employees[i].salary);
    }
    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        displayEmployeeDetails(employees[i]);
    }

    return 0;
}

