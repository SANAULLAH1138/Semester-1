#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 3
#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50

// Structure for Instructor
struct Instructor {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
};

// Structure for Student
struct Student {
    char name[MAX_NAME_LENGTH];
    int roll_no;
    float grade;
};

// Structure for Course
struct Course {
    char course_name[MAX_NAME_LENGTH];
    int course_id;
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int student_count;
};

// Structure for Department
struct Department {
    char dept_name[MAX_NAME_LENGTH];
    struct Course courses[MAX_COURSES];
    int course_count;
};

// Function to add a new department
void addDepartment(struct Department *department) {
    printf("Enter department name: ");
    fgets(department->dept_name, MAX_NAME_LENGTH, stdin);
    department->dept_name[strcspn(department->dept_name, "\n")] = '\0';  // Remove newline character
}

// Function to add a new course to a department
void addCourse(struct Department *department) {
    if (department->course_count >= MAX_COURSES) {
        printf("Cannot add more courses to this department.\n");
        return;
    }

    struct Course *course = &department->courses[department->course_count];
    department->course_count++;

    printf("Enter course name: ");
    fgets(course->course_name, MAX_NAME_LENGTH, stdin);
    course->course_name[strcspn(course->course_name, "\n")] = '\0';  // Remove newline character

    printf("Enter course ID: ");
    scanf("%d", &course->course_id);
    getchar();  // To consume newline left by scanf

    // Input instructor details
    printf("Enter instructor name: ");
    fgets(course->instructor.name, MAX_NAME_LENGTH, stdin);
    course->instructor.name[strcspn(course->instructor.name, "\n")] = '\0';  // Remove newline character

    printf("Enter instructor email: ");
    fgets(course->instructor.email, MAX_NAME_LENGTH, stdin);
    course->instructor.email[strcspn(course->instructor.email, "\n")] = '\0';  // Remove newline character

    // Input students enrolled in the course
    course->student_count = 0;
    while (course->student_count < MAX_STUDENTS) {
        struct Student *student = &course->students[course->student_count];
        printf("Enter student name (or type 'exit' to stop): ");
        fgets(student->name, MAX_NAME_LENGTH, stdin);
        student->name[strcspn(student->name, "\n")] = '\0';  // Remove newline character

        if (strcmp(student->name, "exit") == 0) {
            break;
        }

        printf("Enter student roll number: ");
        scanf("%d", &student->roll_no);
        getchar();  // To consume newline left by scanf

        printf("Enter student grade: ");
        scanf("%f", &student->grade);
        getchar();  // To consume newline left by scanf

        course->student_count++;
    }
}

// Function to display all departments, courses, instructors, and students
void displaySystem(struct Department departments[], int dept_count) {
    for (int i = 0; i < dept_count; i++) {
        printf("\nDepartment: %s\n", departments[i].dept_name);
        for (int j = 0; j < departments[i].course_count; j++) {
            printf("\n  Course Name: %s\n", departments[i].courses[j].course_name);
            printf("  Course ID: %d\n", departments[i].courses[j].course_id);
            printf("  Instructor: %s\n", departments[i].courses[j].instructor.name);
            printf("  Instructor Email: %s\n", departments[i].courses[j].instructor.email);
            printf("  Enrolled Students:\n");
            for (int k = 0; k < departments[i].courses[j].student_count; k++) {
                printf("    Name: %s, Roll No: %d, Grade: %.2f\n",
                    departments[i].courses[j].students[k].name,
                    departments[i].courses[j].students[k].roll_no,
                    departments[i].courses[j].students[k].grade);
            }
        }
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int dept_count = 0;
    int choice;

    while (1) {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Display University System\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline left by scanf

        switch (choice) {
            case 1:
                if (dept_count < MAX_DEPARTMENTS) {
                    addDepartment(&departments[dept_count]);
                    dept_count++;
                } else {
                    printf("Maximum number of departments reached.\n");
                }
                break;
            case 2:
                if (dept_count > 0) {
                    addCourse(&departments[dept_count - 1]);
                } else {
                    printf("No departments available. Please add a department first.\n");
                }
                break;
            case 3:
                if (dept_count > 0) {
                    displaySystem(departments, dept_count);
                } else {
                    printf("No departments available.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

