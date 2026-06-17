#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
#define MAX_COURSES 20

struct Course {
    char course_id[20];
    char course_name[50];
    char instructor_name[50];
    int credits;
};

struct Department {
    char department_name[50];
    struct Course courses[MAX_COURSES];
    int course_count;
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int department_count;
};

void addDepartment(struct University* university) {
    if (university->department_count >= MAX_DEPARTMENTS) {
        printf("Maximum number of departments reached.\n");
        return;
    }

    printf("Enter department name: ");
    getchar();
    fgets(university->departments[university->department_count].department_name, 50, stdin);
    university->departments[university->department_count].department_name[strcspn(
        university->departments[university->department_count].department_name, "\n")] = '\0';
    university->departments[university->department_count].course_count = 0;

    university->department_count++;
    printf("Department added successfully.\n");
}

void addCourse(struct University* university) {
    if (university->department_count == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    printf("Available Departments:\n");
    for (int i = 0; i < university->department_count; i++) {
        printf("%d. %s\n", i + 1, university->departments[i].department_name);
    }

    int dept_index;
    printf("Select department by number: ");
    scanf("%d", &dept_index);

    if (dept_index < 1 || dept_index > university->department_count) {
        printf("Invalid department selected.\n");
        return;
    }

    dept_index--; // Adjust for 0-based indexing
    struct Department* dept = &university->departments[dept_index];

    if (dept->course_count >= MAX_COURSES) {
        printf("Maximum number of courses reached for this department.\n");
        return;
    }

    struct Course* course = &dept->courses[dept->course_count];
    printf("Enter course ID: ");
    getchar();
    fgets(course->course_id, 20, stdin);
    course->course_id[strcspn(course->course_id, "\n")] = '\0';

    printf("Enter course name: ");
    fgets(course->course_name, 50, stdin);
    course->course_name[strcspn(course->course_name, "\n")] = '\0';

    printf("Enter instructor name: ");
    fgets(course->instructor_name, 50, stdin);
    course->instructor_name[strcspn(course->instructor_name, "\n")] = '\0';

    printf("Enter credits: ");
    scanf("%d", &course->credits);

    dept->course_count++;
    printf("Course added successfully.\n");
}

void displayDetails(struct University university) {
    if (university.department_count == 0) {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < university.department_count; i++) {
        struct Department dept = university.departments[i];
        printf("\nDepartment: %s\n", dept.department_name);
        if (dept.course_count == 0) {
            printf("  No courses available.\n");
        } else {
            for (int j = 0; j < dept.course_count; j++) {
                struct Course course = dept.courses[j];
                printf("  Course ID: %s\n", course.course_id);
                printf("  Course Name: %s\n", course.course_name);
                printf("  Instructor: %s\n", course.instructor_name);
                printf("  Credits: %d\n", course.credits);
            }
        }
    }
}

void calculateTotalCredits(struct University university) {
    if (university.department_count == 0) {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < university.department_count; i++) {
        struct Department dept = university.departments[i];
        int total_credits = 0;
        for (int j = 0; j < dept.course_count; j++) {
            total_credits += dept.courses[j].credits;
        }
        printf("Total credits for department %s: %d\n", dept.department_name, total_credits);
    }
}

int main() {
    struct University university = {0};
    int choice;

    do {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Display Details\n");
        printf("4. Calculate Total Credits\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&university);
                break;
            case 2:
                addCourse(&university);
                break;
            case 3:
                displayDetails(university);
                break;
            case 4:
                calculateTotalCredits(university);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

